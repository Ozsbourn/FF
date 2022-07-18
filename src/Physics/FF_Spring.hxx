#include "..\Core\FF_Macros.hxx"
#include "..\Core\FF_CommonMath.hxx"

#include "FF_MaterialPointBase.hxx"

#ifndef FF_SPRING_HXX_
#define FF_SPRING_HXX_

namespace FF {
    template<typename T>
    class Spring {
    private:
        T m_RestLength;
        T m_ForceConstant;
        T m_DampeningFactor;

        FF::MaterialPointBase<T>* m_pm_1;
        FF::MaterialPointBase<T>* m_pm_2;
    public:
        explicit Spring(void) = default;

        inline T    GetLength(void) const;
        inline void SetLength(const T __FF_IN length);

        inline T    GetForce(void) const;
        inline void SetForce(const T __FF_IN force);

        inline T    GetDampening(void) const;
        inline void SetDampening(const T __FF_IN dampening);

        inline FF::MaterialPointBase<T>& GetEndpointMassFirst(void) const;
        inline void                      SetEndpointMassFirst(const FF::MaterialPointBase<T>& __FF_IN pm);

        inline FF::MaterialPointBase<T>& GetEndpointMassSecond(void) const;
        inline void                      SetEndpointMassSecond(const FF::MaterialPointBase<T>& __FF_IN pm);

        inline bool isDisplaced(void);

        void CalculateReactions(const T __FF_IN changeInTime);

        ~Spring(void);
    };

    template<typename T>
    inline T    FF::Spring<T>::GetLength(void) const {
        return this->m_RestLength;
    }

    template<typename T>
    inline void FF::Spring<T>::SetLength(const T __FF_IN length){
        this->m_RestLength = length;
    }

    template<typename T>
    inline T    FF::Spring<T>::GetForce(void) const {
        return this->m_ForceConstant;
    }

    template<typename T>
    inline void FF::Spring<T>::SetForce(const T __FF_IN force){
        this->m_ForceConstant = force;
    }

    template<typename T>
    inline T    FF::Spring<T>::GetDampening(void) const {
        return this->m_DampeningFactor;
    }

    template<typename T>
    inline void FF::Spring<T>::SetDampening(const T __FF_IN dampening){
        this->m_DampeningFactor = dampening;
    }

    template<typename T>
    inline FF::MaterialPointBase<T>& FF::Spring<T>::GetEndpointMassFirst(void) const {
        return this->m_pm_1;;
    }

    template<typename T>
    inline void                      FF::Spring<T>::SetEndpointMassFirst(const FF::MaterialPointBase<T>& __FF_IN pm){
        this->m_pm_1 = &pm;
    }

    template<typename T>
    inline FF::MaterialPointBase<T>& FF::Spring<T>::GetEndpointMassSecond(void) const {
        return this->m_pm_2;
    }

    template<typename T>
    inline void                      FF::Spring<T>::SetEndpointMassSecond(const FF::MaterialPointBase<T>& __FF_IN pm){
        this->m_pm_2 = &pm;
    }

    template<typename T>
    inline bool FF::Spring<T>::isDisplaced(void){
        FF_ASSERT(m_pm_1 != nullptr);
        FF_ASSERT(m_pm_2 != nullptr);

        // Find the distance above points which attached spring
        FF::Vector3<T> CurrentLength = m_pm_1->Location() - m_pm_2->Location();

        // Find the subdiv above current length and rest length
        T DistanceDifference = CurrentLength.SquaredDistance() - FF::sqr(this->GetLength());

        return (!CloseToZero(DistanceDifference)) ? true : false ;
    }

    template<typename T>
    inline void FF::Spring<T>::CalculateReactions(const T __FF_IN changeInTime){
        FF_ASSERT(m_pm_1 != nullptr);
        FF_ASSERT(m_pm_2 != nullptr);

        // Find the distance above points which attached spring
        FF::Vector3<T> CurrentLength = m_pm_1->Location() - m_pm_2->Location();

        // Find the subdiv above current length and rest length
        T DistanceDifference = CurrentLength.SquaredDistance() - FF::sqr(this->GetLength());

        if (!CloseToZero(DistanceDifference)) {
            DistanceDifference = static_cast<T>(0.0);
        }

        // Find magnitude of force that hav a spring
        T SpringForceMagnitude = this->GetForce() * DistanceDifference;
        T DampeningForceMagnitude = (changeInTime < 1.0f) ? (this->GetDampening() * DistanceDifference * changeInTime) 
                                                            : (this->GetDampening() * DistanceDifference / changeInTime) ;

        // The dampening force can't be greater than the spring force
        if (DampeningForceMagnitude > SpringForceMagnitude) {
            DampeningForceMagnitude = SpringForceMagnitude;
        }

        //Dampen the spring force
        T ResponseForceMagnitude = SpringForceMagnitude - DampeningForceMagnitude;

        // Change the response force to a vector
        FF::Vector3<T> ResponseForce = ResponseForceMagnitude * FF::Normalize(CurrentLength);

        // Apply the response force to the particles
        m_pm_1->SetImpulseForce(m_pm_1->GetImpulseForce() + -0x1 * ResponseForce);
        m_pm_2->SetImpulseForce(m_pm_2->GetImpulseForce() + ResponseForce);
    }
};

#endif // FF_SPRING_HXX_