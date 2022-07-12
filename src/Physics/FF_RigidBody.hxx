#include "..\Core\FF_Macros.hxx"
#include "..\Core\FF_Vector3.hxx"
#include "..\Core\FF_Quaternion.hxx"

#include "FF_Force.hxx"

#ifndef FF_RIGIDBODY_HXX_
#define FF_RIGIDBODY_HXX_

namespace FF {
	template<typename T>
	class RigidBody {
	private:
		T m_InvertMass;
		T m_Restitution;
		T m_Friction;

		FF::Vector3<T>    m_Location;
		FF::Quaternion<T> m_Orientation;

		FF::Vector3<T> 	  m_LinearVelocity;
		FF::Vector3<T> 	  m_LinearAcceleration;

		FF::Vector3<T> 	  m_AngularVelocity;
		FF::Vector3<T> 	  m_AngularAcceleration;

		FF::Force<T>	  m_SumForces;

		bool 			  m_isStatic;
	public:
		explicit MaterialPoint(void) = delete;

		explicit MaterialPoint( T 			   __FF_IN mass 	  	 = static_cast<T>(0.0f),
								FF::Vector3<T> __FF_IN massCenter 	 = FF::Vector3<T>(0.0f, 0.0f, 0.0f),
								FF::Vector3<T> __FF_IN lVelocity 	 = FF::Vector3<T>(0.0f, 0.0f, 0.0f),
								FF::Vector3<T> __FF_IN lAcceleration = FF::Vector3<T>(0.0f, 0.0f, 0.0f),
								FF::Vector3<T> __FF_IN aVelocity 	 = FF::Vector3<T>(0.0f, 0.0f, 0.0f),
								FF::Vector3<T> __FF_IN aAcceleration = FF::Vector3<T>(0.0f, 0.0f, 0.0f),
								FF::Vector3<T> __FF_IN sumForce      = FF::Vector3<T>(0.0f, 0.0f, 0.0f),
								bool 		   __FF_IN staticFlag	 = false )
		: m_InverseMass(0x1 / mass),
		  m_Location(massCenter),
		  m_LinearVelocity(lVelocity),
		  m_LinearAcceleration(lAcceleration),
		  m_AngularVelocity(aVelocity),
		  m_AngularAcceleration(aAcceleration),
		  m_SumForces(sumForce),
		  m_isStatic(staticFlag) {};

		inline const T GetMass(void) const;
		inline const T GetInvertMass(void) const;
		inline void    SetMass(const T __FF_IN mass);
		inline void    SetInvertMass(const T __FF_IN mass); 

		inline const FF::Vector3<T> GetLocation(void) const;
		inline void    				SetLocation(const FF::Vector3<T>& __FF_IN location);	

		inline const FF::Vector3<T> GetLinearVelocity(void) const;
		inline void 		   		SetLinearVelocity(const FF::Vector3<T>& __FF_IN velocity);

		inline const FF::Vector3<T> GetLinearAcceleration(void) const;
		inline void 		   		SetLinearAcceleration(const FF::Vector3<T>& __FF_IN acceleration);

		inline const FF::Vector3<T> GetAngularVelocity(void) const;
		inline void 		   		SetAngularVelocity(const FF::Vector3<T>& __FF_IN velocity);

		inline const FF::Vector3<T> GetAngularAcceleration(void) const;
		inline void 		   		SetAngularAcceleration(const FF::Vector3<T>& __FF_IN acceleration);

		inline const FF::Vector3<T> GetForce(void) const;
		inline void 		   		SetForce(const FF::Vector3<T>& __FF_IN force);
		inline void 				AddForce(const FF::Vector3<T>& __FF_IN force)		

		inline const bool Update(const T __FF_IN changeInTime);

		~MaterialPoint(void) = default;	
	};

	template<typename T>
	inline const T GetMass(void) const {
		return (0x1 / this->m_InvertMass);
	}

	template<typename T>
	inline const T GetInvertMass(void) const {
		return this->m_InvertMass;
	}

	template<typename T>
	void SetMass(T __FF_IN mass){
		this->m_InvertMass = 0x1 / mass;
	}

	template<typename T>
	void SetInvertMass(T __FF_IN mass){
		this->m_InvertMass = mass;
	}

	template<typename T>
	inline const FF::Vector3<T> GetLocation(void) const {
		return this->m_Location;
	}

	template<typename T>
	inline void    				SetLocation(const FF::Vector3<T>& __FF_IN location){
		this->m_Location = location;
	}	

	template<typename T>
	inline const FF::Vector3<T> GetLinearVelocity(void) const {
		return this->m_LinearVelocity;
	}

	template<typename T>
	inline void 		   		SetLinearVelocity(const FF::Vector3<T>& __FF_IN velocity){
		this->m_LinearVelocity = velocity;
	}

	template<typename T>
	inline const FF::Vector3<T> GetLinearAcceleration(void) const {
		return this->m_LinearAcceleration;
	}

	template<typename T>
	inline void 		   		SetLinearAcceleration(const FF::Vector3<T>& __FF_IN acceleration){
		this->m_LinearAcceleration = acceleration;
	}

	template<typename T>
	inline const FF::Vector3<T> GetAngularVelocity(void) const {
		return this->m_AngularVelocity;
	}

	template<typename T>
	inline void 		   		SetAngularVelocity(const FF::Vector3<T>& __FF_IN velocity){
		this->m_AngularVelocity = velocity;
	}

	template<typename T>
	inline const FF::Vector3<T> GetAngularAcceleration(void) const {
		return this->m_AngularAcceleration;
	}

	template<typename T>
	inline void 		   		SetAngularAcceleration(const FF::Vector3<T>& __FF_IN acceleration){
		this->m_AngularAcceleration = acceleration;
	}

	template<typename T>
	inline const FF::Force<T> GetForce(void) const {
		return this->m_SumForces;
	}

	template<typename T>
	inline void 		   		SetForce(const FF::Force<T>& __FF_IN force){
		this->m_SumForces = force;
	}

	template<typename T>
	inline void 				AddForce(const FF::Force<T>& __FF_IN force){
		this->m_SumForces += force;
	}

	template<typename T>
	inline const bool Update(const T __FF_IN changeInTime){
		m_LinearAcceleration = m_SumForces / m_InvertMass;

		m_LinearVelocity += m_LinearAcceleration   * changeInTime;
		m_Location += m_LinearVelocity * changeInTime;
	}
};

#endif // FF_RIGIDBODY_HXX_