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

        inline void HandleCollision( FF::Vector3<T> separationDistance,
                                     T              changeInTime,
                                     FF::IndexPair  firstParticle,
                                     FF::IndexPair  secondParticle );
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

        inline void           SetParticleImpulseForce(std::size_t row,  std::size_t column, const FF::Vector3<T>& impulseForce);
        inline FF::Vector3<T> GetParticleImpulseForce(std::size_t row,  std::size_t column);
        inline void           SetParticleConstantForce(std::size_t row, std::size_t column, const FF::Vector3<T>& constantForce);
        inline FF::Vector3<T> GetParticleConstantForce(std::size_t row, std::size_t column);

        inline bool isParticleStatic(std::size_t row, std::size_t column);
        inline void SetParticleStaticFlag(std::size_t row, std::size_t column, bool flag);

        inline bool Update(const T changeInTime);
        inline bool Render(void);

        ~Cloth(void);
    };

    /**
     * @brief [Constructor that get IS_STATIC flag for particle]
     * @details [Constructor allocate the memory and set positions and properties according to parameters]
     * 
     * @param rows [Row in particle buffer]
     * @param columns [Columns in particle buffer]
     * @param particleMass [Mass of one particle]
     * @param particleRadius [Radius of one particle]
     * @param particleElasticity [Restitution of particle]
     * @param spaceBetweenParticles [Space between two particles]
     * @param clothStiffness [Stiffness for each spring]
     * @param dampeningFactor [Dampening for each spring]
     * @param linearDampeningFactor [Linear dampening for cloth]
     * @param upLeftCorner [Location of up left corner cloth]
     * @tparam T [Generic type]
     * 
     * @return [-]
     */
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

    /**
     * @brief [Method that set impulse force (i, j) particle from PARTICLE_BUFFER]
     * @details [-]
     * 
     * @@param row [Row in PARTICLE_BUFFER]
     * @param column [Column in PARTICLE_BUFFER]
     * @param impulseForce [Vector3 that represent IMPULSE_FORCE of particle]
     * @tparam T [Generic Type]
     * 
     * @return [-]
     */
    template<typename T>
    inline void FF::Cloth<T>::SetParticleImpulseForce(std::size_t row, std::size_t column, const FF::Vector3<T>& impulseForce){
        FF_ASSERT_MESSAGE((row >= 0x0 && row < this->m_TotalRows), "Going beyond particle buffer! Check row index!");
        FF_ASSERT_MESSAGE((column >= 0x0 && column < this->m_TotalColumns), "Going beyond particle buffer! Check column index!");
        
        this->m_Particles[row][column].SetImpulseForce(impulseForce);
    }

    /**
     * @brief [Method that get impulse force (i, j) particle from PARTICLE_BUFFER]
     * @details [-]
     * 
     * @param row [Row in PARTICLE_BUFFER]
     * @param column [Column in PARTICLE_BUFFER]
     * @param impulseForce [Vector3 that represent IMPULSE_FORCE of particle]
     * @tparam T [Generic Type]
     * 
     * @return [Return impulse force of (i, j) particle in PARTICLE_BUFFER]
     */
    template<typename T>
    inline FF::Vector3<T> FF::Cloth<T>::GetParticleImpulseForce(std::size_t row, std::size_t column){
        FF_ASSERT_MESSAGE((row >= 0x0 && row < this->m_TotalRows), "Going beyond particle buffer! Check row index!");
        FF_ASSERT_MESSAGE((column >= 0x0 && column < this->m_TotalColumns), "Going beyond particle buffer! Check column index!");
        
        return (this->m_Particles[row][column].GetImpulseForce());
    }

    /**
     * @brief [Method that set constant force (i, j) particle from PARTICLE_BUFFER]
     * @details [-]
     * 
     * @param row [Row in PARTICLE_BUFFER]
     * @param column [Column in PARTICLE_BUFFER]
     * @param impulseForce [Vector3 that represent CONSTANT_FORCE of particle]
     * @tparam T [Generic Type]
     * 
     * @return [-]
     */
    template<typename T>
    inline void FF::Cloth<T>::SetParticleConstantForce(std::size_t row, std::size_t column, const FF::Vector3<T>& constantForce){
        FF_ASSERT_MESSAGE((row >= 0x0 && row < this->m_TotalRows), "Going beyond particle buffer! Check row index!");
        FF_ASSERT_MESSAGE((column >= 0x0 && column < this->m_TotalColumns), "Going beyond particle buffer! Check column index!");
        
        this->m_Particles[row][column].SetConstantForce(constantForce);
    }

    /**
     * @brief [Method that get constant force of (i, j) particle in PARTICLE_BUFFER]
     * @details [-]
     * 
     * @param row [Row in PARTICLE_BUFFER]
     * @param column [Column in PARTICLE_BUFFER]
     * @param impulseForce [Vector3 that represent CONSTANT_FORCE of particle]
     * @tparam T [Generic Type]
     * 
     * @return [Return constant force of (i, j) particle in PARTICLE_BUFFER]
     */
    template<typename T>
    inline FF::Vector3<T> FF::Cloth<T>::GetParticleConstantForce(std::size_t row, std::size_t column){
        FF_ASSERT_MESSAGE((row >= 0x0 && row < this->m_TotalRows), "Going beyond particle buffer! Check row index!");
        FF_ASSERT_MESSAGE((column >= 0x0 && column < this->m_TotalColumns), "Going beyond particle buffer! Check column index!");
        
        return (this->m_Particles[row][column].GetConstantForce());
    }

    /**
     * @brief [Method that get IS_STATIC flag for particle]
     * @details [-]
     * 
     * @param row [Row in particle buffer]
     * @param column [Column in particle buffer]
     * @tparam T [Generic type]
     * 
     * @return [Flag that represent move ability for particle]
     */
    template<typename T>
    inline bool FF::Cloth<T>::isParticleStatic(std::size_t row, std::size_t column){
        FF_ASSERT_MESSAGE((row >= 0x0 && row < this->m_TotalRows), "Going beyond particle buffer! Check row index!");
        FF_ASSERT_MESSAGE((column >= 0x0 && column < this->m_TotalColumns), "Going beyond particle buffer! Check column index!");

        return this->m_Particles[row][column].isStatic();
    }

    /**
     * @brief [Method that set IS_STATIC flag for particle]
     * @details [-]
     * 
     * @param row [Row in particle buffer]
     * @param column [Column in particle buffer]
     * @tparam T [Generic type]
     * 
     * @return [-]
     */
    template<typename T>
    inline void FF::Cloth<T>::SetParticleStaticFlag(std::size_t row, std::size_t column, bool flag){
        FF_ASSERT_MESSAGE((row >= 0x0 && row < this->m_TotalRows), "Going beyond particle buffer! Check row index!");
        FF_ASSERT_MESSAGE((column >= 0x0 && column < this->m_TotalColumns), "Going beyond particle buffer! Check column index!");

        this-m_Particles[row][column].SetStaticFlag();
    }

    /**
     * @brief [Method update states from each particle from PARTICLE_BUFFER]
     * @details [-]
     * 
     * @param changeInTime [Frame of time that need to recalculate states]
     * @tparam T [Generic type]
     * @return [-]
     */
    template<typename T>
    inline bool FF::Cloth<T>::Update(const T changeInTime){
        std::size_t i,j;

        // Calculate the force exerted by each spring
        for (i = 0x0; i < this->m_TotalSprings; i++) {
            if (this->m_Springs[i].IsDisplaced()) {
                this->m_Springs[i].CalculateReactions(changeInTime);
            }
        }

        // Update the position of every particle in the grid.
        for (i = 0x0; i < this->m_TotalRows; i++) {
            for (j = 0x0; j < this->m_TotalColumns; j++) {
                for (std::size_t k = i; k < this->m_TotalColumns; k++) {
                    for (std::size_t m = j + 0x1; m < this->m_TotalColumns; m++) {
                        // Find the distance vector between the particles.
                        FF::Vector3<T> distance = this->m_Particles[i][j].GetLocation() - this->m_Particles[k][m].GetLocation();
                        T distanceSquared = FF::SquaredMagnitude(distance);

                        // Find the square of the sum of the radii of the balls.
                        T minDistanceSquared = this->m_Particles[i][j].GetBoundingSphereRadius() + this->m_Particles[k][m].GetBoundingSphereRadius();
                        minDistanceSquared *= minDistanceSquared;

                        // If there is a collision
                        if (distanceSquared < minDistanceSquared) {
                            IndexPair firstParticle, secondParticle;
                            firstParticle.m_row     = i;
                            firstParticle.m_column  = j;
                            secondParticle.m_row    = k;
                            secondParticle.m_column = m;

                            // Handle the collision.
                            HandleCollision(distance, changeInTime, firstParticle, secondParticle);
                        }
                    }
                }
            }
        }

        FF::Vector3<T> dampening;
        for (i = 0x0;i < this->m_TotalRows; i++) {
            for (j = 0x0; j < this->m_TotalColumns; j++) {
                dampening = -this->m_linearDampeningCoefficient * this->m_Particles[i][j].GetLinearVelocity();
                this->m_Particles[i][j].SetLinearVelocity(this->m_Particles[i][j].GetLinearVelocity() + dampening);
            }
        }

        // Update each ball.
        for (i = 0x0; i < this->m_TotalRows; i++) {
            for (j = 0x0; j < this->m_TotalColumns; j++) {
                this->m_Particles[i][j].Update(changeInTime);
            }
        }

        return true;
    }

    /**
     * @brief [Method that render cloth]
     * @details [Render each of particle that consists in cloth]
     * 
     * @tparam T [Generic type]
     * @return [Return status of render cloth]
     */
    template<typename T>
    inline bool FF::Cloth<T>::Render(void){
        bool RenderStatus = true;

        for (std::size_t i = 0x0; RenderStatus && i < this->m_TotalRows; i++) {
            for (std::size_t  j = 0x0; RenderStatus && j < this->m_TotalColumns; j++) {
                RenderStatus = this->m_Particles[i][j].Render();
            }
        }

        return (RenderStatus);
    }
};

#endif // FF_CLOTH_HXX_