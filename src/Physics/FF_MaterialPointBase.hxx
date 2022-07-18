#include "..\Core\FF_Macros.hxx"
#include "..\Core\FF_Vector3.hxx"

#include "FF_Force.hxx"

#ifndef FF_MATERIALPOINTBASE_HXX_
#define FF_MATERIALPOINTBASE_HXX_

namespace FF {
    template<typename T>
    class MaterialPointBase {
    private:
        T              m_Mass;
        T              m_InvertMass;

        T              m_Restitution;
        T              m_BoundedSphereRadius;
        
        FF::Vector3<T> m_Location;
        FF::Vector3<T> m_LinearVelocity;
        FF::Vector3<T> m_LinearAcceleration;

        FF::Force<T>   m_ConstantForce;
        FF::Force<T>   m_ImpulseForce;

        bool           m_isStatic;
    public:
        explicit MaterialPointBase(void) = delete;

        explicit MaterialPointBase( T               mass                = static_cast<T>(0.0f),
                                    T               restitution         = static_cast<T>(0.0f),
                                    T               boundedSphereRadius = static_cast<T>(0.0f),

                                    FF::Vector3<T>& location      = FF::Vector3<T>(0.0f, 0.0f, 0.0f),
                                    FF::Vector3<T>& velocity      = FF::Vector3<T>(0.0f, 0.0f, 0.0f),
                                    FF::Vector3<T>& acceleration  = FF::Vector3<T>(0.0f, 0.0f, 0.0f),

                                    FF::Force<T>&   constantForce = FF::Force<T>(FF::Vector3<T>(0.0f, 0.0f, 0.0f), FF::Vector3<T>(0.0f, 0.0f, 0.0f)),
                                    FF::Force<T>&   impulseForce  = FF::Force<T>(FF::Vector3<T>(0.0f, 0.0f, 0.0f), FF::Vector3<T>(0.0f, 0.0f, 0.0f)),

                                    bool            isStatic = false )
        : m_Mass(mass), 
          m_InvertMass(0x1 / mass),
          m_Restitution(restitution),
          m_BoundedSphereRadius(boundedSphereRadius),
          m_Location(location),
          m_LinearVelocity(velocity),
          m_LinearAcceleration(acceleration),
          m_ConstantForce(constantForce),
          m_ImpulseForce(impulseForce),
          m_isStatic(isStatic) {}

        explicit MaterialPointBase(FF::MaterialPointBase<T>& mp);

        inline const T GetMass(void) const;
        inline void    SetMass(const T mass); 

        inline const T GetInvertMass(void) const;
        inline void    SetInvertMass(const T mass); 

        inline const T GetRestitution(void) const;
        inline void    SetRestitution(const T restitution);

        inline const T GetBoundedSphereRadius(void) const;
        inline void    SetBoundedSphereRadius(const T radius);

        inline const FF::Vector3<T> GetLocation(void) const;
        inline void                 SetLocation(FF::Vector3<T>& location);

        inline const FF::Vector3<T> GetVelocity(void) const;
        inline void                 SetVelocity(FF::Vector3<T>& velocity);    

        inline const FF::Vector3<T> GetAcceleration(void) const;
        inline void                 SetAcceleration(FF::Vector3<T>& acceleration);

        inline const FF::Force<T>   GetConstantForce(void) const;
        inline void                 SetConstantForce(FF::Force<T>& force);

        inline const FF::Force<T>   GetImpulseForce(void) const;
        inline void                 SetImpulseForce(FF::Force<T>& force);

        inline const bool           isStatic(void);

        virtual inline const bool Update(const T changeInTime);

        ~MaterialPointBase(void) = default;    
    };

    template<typename T>
    FF::MaterialPointBase<T>::MaterialPointBase(FF::MaterialPointBase<T>& mp){
        this->m_Mass                = mp.GetMass();
        this->m_InvertMass          = mp.GetInvertMass();
        this->m_Restitution         = mp.GetRestitution();
        this->m_BoundedSphereRadius = mp.GetBoundedSphereRadius();
        this->m_Location            = mp.GetLocation();
        this->m_LinearVelocity      = mp.GetVelocity();
        this->m_LinearAcceleration  = mp.GetAcceleration();
        this->m_ConstantForce       = mp.GetConstantForce();
        this->m_ImpulseForce        = mp.GetImpulseForce();
        this->m_isStatic            = mp.isStatic();
    }

    template<typename T>
    inline const T FF::MaterialPointBase<T>::GetMass(void) const {
        return 0x1 / this->m_Mass;
    }

    template<typename T>
    inline void    FF::MaterialPointBase<T>::SetMass(const T mass){
        this->m_Mass = 0x1 / mass;
    }

    template<typename T>
    inline const T FF::MaterialPointBase<T>::GetInvertMass(void) const {
        return this->m_InvertMass;
    }

    template<typename T>
    inline void    FF::MaterialPointBase<T>::SetInvertMass(const T mass){
        this->m_InvertMass = mass;
    }

    template<typename T>
    inline const T FF::MaterialPointBase<T>::GetRestitution(void) const {
        return this->m_Restitution;
    }

    template<typename T>
    inline void FF::MaterialPointBase<T>::SetRestitution(T restitution){
        this->m_Restitution = restitution;
    }

    template<typename T>
    inline const T FF::MaterialPointBase<T>::GetBoundedSphereRadius(void) const {
        return this->m_BoundedSphereRadius;
    }

    template<typename T>
    inline void FF::MaterialPointBase<T>::SetBoundedSphereRadius(T radius){
        this->m_BoundedSphereRadius = radius;
    }

    template<typename T>
    inline const FF::Vector3<T> FF::MaterialPointBase<T>::GetVelocity(void) const {
        return this->m_LinearVelocity;
    }

    template<typename T>
    inline void FF::MaterialPointBase<T>::SetVelocity(FF::Vector3<T>& velocity){
        if (m_isStatic) {
            this->m_LinearVelocity = FF::Vector3<T>(0.0f, 0.0f, 0.0f);
        } else {
            this->m_LinearVelocity = velocity;
        }
    }

    template<typename T>
    inline const FF::Vector3<T> FF::MaterialPointBase<T>::GetLocation(void) const {
        return this->m_Location;
    }
    template<typename T>
    inline void FF::MaterialPointBase<T>::SetLocation(FF::Vector3<T>& location){
        this->m_Location = location;
    }    

    template<typename T>
    inline const FF::Vector3<T> FF::MaterialPointBase<T>::GetAcceleration(void) const {
        return this-> m_LinearAcceleration;
    }

    template<typename T>
    inline void FF::MaterialPointBase<T>::SetAcceleration(FF::Vector3<T>& acceleration){
        if (m_isStatic) {
            this->m_LinearAcceleration = FF::Vector3<T>(0.0f, 0.0f, 0.0f);
        } else {
            this->m_LinearAcceleration = acceleration;
        }
    }

    template<typename T>
    inline const FF::Force<T> FF::MaterialPointBase<T>::GetConstantForce(void) const {
        return this->m_ConstantForce;
    }

    template<typename T>
    inline void FF::MaterialPointBase<T>::SetConstantForce(FF::Force<T>& force){
        if (m_isStatic) {
            this->m_ConstantForce = FF::Force<T>(FF::Vector3<T>(0.0f, 0.0f, 0.0f), FF::Vector3<T>(0.0f, 0.0f, 0.0f));
        } else {
            this->m_ConstantForce = force;
        }
    }

    template<typename T>
    inline const FF::Force<T> FF::MaterialPointBase<T>::GetImpulseForce(void) const {
        return this->m_ImpulseForces;
    }

    template<typename T>
    inline void FF::MaterialPointBase<T>::SetImpulseForce(FF::Force<T>& force){
        if (m_isStatic) {
            this->m_ImpulseForces = FF::Force<T>(FF::Vector3<T>(0.0f, 0.0f, 0.0f), FF::Vector3<T>(0.0f, 0.0f, 0.0f));
        } else {
            this->m_ImpulseForces = force;
        }
    }

    template<typename T>
    inline const bool FF::MaterialPointBase<T>::isStatic(void){
        return this->m_isStatic;
    }

    template<typename T>
    inline const bool FF::MaterialPointBase<T>::Update(const T changeInTime) {
        /*FF_ASSERT(m_Mass != 0x0);
        m_LinearAcceleration = (m_ConstantForce + m_ImpulseForce) / m_Mass;

        m_ImpulseForce = FF::Vector3<T>(0.0f, 0.0f, 0.0f);

        m_LinearVelocity += m_LinearAcceleration   * changeInTime;
        m_Location       += m_LinearVelocity       * changeInTime;*/

        // to-do: create matrix translation
        return true;
    }

    template<typename T> using InvisibleMaterialPoint = FF::MaterialPointBase<T>;
};

#endif // FF_MATERIALPOINTBASE_HXX_