#include "..\Core\FF_Macros.hxx"
#include "..\Core\FF_CommonMath.hxx"

#include "..\Core\FF_Vector3.hxx"
#include "FF_Spring.hxx"
#include "FF_MaterialPointBase.hxx"

#ifndef FF_CLOTH_HXX_
#define FF_CLOTH_HXX_

namespace FF {
    enum CLOTH_CONSTANTS {
        FF_PARTICLES_PER_SQUARE            = 0x4,
        
        FF_TOP_LEFT_PARTICLE               = 0x0,
        FF_TOP_RIGHT_PARTICLE              = 0x1,
        FF_BOTTOM_LEFT_PARTICLE            = 0x2,
        FF_BOTTOM_RIGHT_PARTICLE           = 0x3,

        FF_SPRINGS_PER_SQUARE              = 0x6,

        FF_TOP_SPRING                      = 0x0,
        FF_BOTTOM_SPRING                   = 0x1,
        FF_RIGHT_SPRING                    = 0x2,
        FF_LEFT_SPRING                     = 0x3,
        FF_TOP_RIGHT_TO_BOTTOM_LEFT_SPRING = 0x4,
        FF_TOP_LEFT_TO_BOTTOM_RIGHT_SPRING = 0x5
    };

    struct IndexPair {
        std::size_t m_row;
        std::size_t m_column;
    };

    struct ClothSquare {
        FF::IndexPair m_ParticleIndex[FF::CLOTH_CONSTANTS::FF_PARTICLES_PER_SQUARE];
        std::size_t   m_SpringIndex[FF::CLOTH_CONSTANTS::FF_SPRINGS_PER_SQUARE]; 
    };

    template<typename T>
    class Cloth {
    private:
        std::size_t                m_TotalRows;
        std::size_t                m_TotalColumns;
        std::size_t                m_TotalSprings;

        FF::MaterialPointBase<T>** m_Particles;
        FF::Spring<T>*             m_Springs;
        FF::ClothSquare**          m_Squares;

        T                          m_LinearDampeningCoefficient;

    public:
        explicit Cloth(void) = delete;

        explicit Cloth( std::size_t    __FF_IN rows, 
                        std::size_t    __FF_IN columns,
                        T              __FF_IN particleMass,
                        T              __FF_IN particleRadius,
                        T              __FF_IN particleElasticity,
                        T              __FF_IN spaceBetweenParticles,
                        T              __FF_IN clothStiffness,
                        T              __FF_IN dampeningFactor,
                        T              __FF_IN linearDampeningFactor,
                        FF::Vector3<T> __FF_IN upLeftCorner );

        ~Cloth(void);
    };

    template<typename T>
    inline FF::Cloth<T>::Cloth( std::size_t    __FF_IN rows, 
                                std::size_t    __FF_IN columns,
                                T              __FF_IN particleMass,
                                T              __FF_IN particleRadius,
                                T              __FF_IN particleElasticity,
                                T              __FF_IN spaceBetweenParticles,
                                T              __FF_IN clothStiffness,
                                T              __FF_IN dampeningFactor,
                                T              __FF_IN linearDampeningFactor,
                                FF::Vector3<T> __FF_IN upLeftCorner ){
        FF_ASSERT(rows    >= 0x2);
        FF_ASSERT(columns >= 0x2);

        this->m_LinearDampeningCoefficient = dampeningFactor;

        this->m_Particles = new FF::MaterialPointBase<T>*[rows];

        if (this->m_Particles == nullptr) {
            //to - do: exception can't alloc memory for cloth
        }

        for (std::size_t i = 0x0; i < rows; i++) {
            this->m_Particles[i] = new FF::MaterialPointBase<T>[columns];

            if (this->m_Particles[i] == nullptr) {
                //to-do: exception can't alloc memory for cloth
            }
        }

        this->m_TotalSprings = (rows * (columns - 0x1)) +
                                ((rows - 0x1) * columns) +
                                 ((rows - 0x1) * (columns - 0x1) * 0x2);

        this->m_Springs = new FF::Spring<T>[this->m_TotalSprings];

        if (this->m_Springs == nullptr) {
            //to-do: exception can't alloc memory for cloth
        } else {
            for (std::size_t i = 0x0; i < rows; i++) {
                this->m_Squares = new FF::ClothSquare[columns - 0x1];

                if (this->m_Squares == nullptr) {
                    //to-do: exception can't alloc memory for cloth    
                }
            }
        }

        FF::Vector3<T> location = upLeftCorner;

        for (std::size_t i = 0x0; i < rows; i++) {
            for (std::size_t j = 0x0; j < columns; j++) {
                this->m_Particles[i][j].SetInvertMass(particleMass);
                this->m_Particles[i][j].SetBoundedSphereRadius(particleRadius);
                this->m_Particles[i][j].SetRestitution(particleElasticity);
                this->m_Particles[i][j].SetLocation(location);
                location.SetXComponent(location.GetXComponent() + spaceBetweenParticles);          
            }
            location.SetXComponent(upLeftCorner.GetXComponent());
            location.SetYComponent(location.GetYComponent() - spaceBetweenParticles);
        }

        FF::IndexPair tmpIndex;
        int currSpring;
        for (std::size_t i = 0x0; i < rows; i++) {
            for (std::size_t j = 0x0; j < columns; j++, currSpring++) {
                // Connect to the top
                this->m_Springs[currSpring].SetEndpointMassFirst(&this->m_Particles[i][j]);
                this->m_Springs[currSpring].SetEndpointMassSecond(&this->m_Particles[i][j + 0x1]);

                if (i < rows - 0x1) {
                    // Store the index of the left spring
                    this->m_Squares[i][j].m_SpringIndex[FF::CLOTH_CONSTANTS::FF_LEFT_SPRING] = currSpring;

                    // Store the indices of the two particles it connects
                    tmpIndex.m_row    = i;
                    tmpIndex.m_column = j;
                    this->m_Squares[i][j].m_ParticleIndex[FF::CLOTH_CONSTANTS::FF_TOP_LEFT_PARTICLE] = tmpIndex;
                    tmpIndex.m_row = i + 0x1;
                    this->m_Squares[i][j].m_ParticleIndex[FF::CLOTH_CONSTANTS::FF_BOTTOM_LEFT_PARTICLE] = tmpIndex;
                }

                // If this is not the first column of particles
                if (j > 0x0) {
                    // Store the index of the bottom spring
                    this->m_Squares[i][j - 0x1].m_SpringIndex[FF::CLOTH_CONSTANTS::FF_RIGHT_SPRING] = currSpring;

                    // Store the indices of the two particles it connects
                    tmpIndex.m_row = i;
                    tmpIndex.m_column = j;
                    this->m_Squares[i][j - 0x1].m_ParticleIndex[FF::CLOTH_CONSTANTS::FF_TOP_RIGHT_PARTICLE] = tmpIndex;
                    tmpIndex.m_row = i + 0x1;
                    this->m_Squares[i][j - 0x1].m_ParticleIndex[FF::CLOTH_CONSTANTS::FF_BOTTOM_RIGHT_PARTICLE] = tmpIndex;
                }
            }
        }

        // For each square, connect the diagonal springs
        for (std::size_t i = 0x0; i < rows - 0x1; i++) {
            for (std::size_t j = 0x0; j < columns - 0x1; j++) {
                // Connect the spring from the top left to the bottom right
                this->m_Springs[currSpring].SetEndpointMassFirst(&this->m_Particles[i][j]);
                this->m_Springs[currSpring].SetEndpointMassSecond(&this->m_Particles[i + 0x1][j + 0x1]);
                this->m_Squares[i][j].m_SpringIndex[FF::CLOTH_CONSTANTS::FF_TOP_RIGHT_TO_BOTTOM_LEFT_SPRING] = currSpring++;

                // Connect the spring from the top right to the bottom left
                this->m_Springs[currSpring].SetEndpointMassFirst(&this->m_Particles[i][j + 0x1]);
                this->m_Springs[currSpring].SetEndpointMassSecond(&this->m_Particles[i + 0x1][j]);
                this->m_Squares[i][j].m_SpringIndex[FF::CLOTH_CONSTANTS::FF_TOP_LEFT_TO_BOTTOM_RIGHT_SPRING] = currSpring++;
            }
        }

        // Set the common properties of all springs
        for (std::size_t i = 0x0; i < this->m_TotalSprings; i++) {
            this->m_Springs[i].SetDampening(dampeningFactor);
            this->m_Springs[i].SetForce(clothStiffness);

            FF::Vector3<T> tmpVector = this->m_Springs[i].GetEndpointMassFirst()->GetLocation() - this->m_Springs[i].GetEndpointMassSecond()->GetLocation();
            this->m_Springs[i].GetLength(FF::Magnitude(tmpVector));
        }

        this->m_TotalRows    = rows;
        this->m_TotalColumns = columns;
    }
};

#endif // FF_CLOTH_HXX_