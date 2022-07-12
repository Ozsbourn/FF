#include "..\..\Core\FF_Vector3.hxx"

#ifndef FF_BOUNDEDSPHERE_HXX_
#define FF_BOUNDEDSPHERE_HXX_

namespace FF {
	template<typename T>
	class BoundedSphere {
	private:
		T 			   m_Radius;
		FF::Vector3<T> m_Location;
	public:
		explicit BoundedSphere(void) = delete;

		explicit BoundedSphere( FF::Vector3<T>& location, 
								T radius ) 
		: m_Location(location), m_radius(radius) {}

		explicit BoundedSphere(FF::BoundedSphere<T> sphere);

		inline void     SetLocation(const FF::Vector3<T>& location);
		inline const T& GetLocation(void) const;

		inline void     SetRadius(const T& radius);
		inline const T& GetRadius(void) const;		

		~BoundedSphere(void) = default;	
	};

	template<typename T>
	FF::BoundedSphere<T>::BoundedSphere(FF::BoundedSphere<T> sphere){
		this->m_Location = sphere.GetLocation();
		this->m_Radius   = sphere.GetRadius();
	}

	template<typename T>
	inline void     FF::BoundedSphere<T>::SetLocation(const FF::Vector3<T>& location){
		this->m_Location = location;
	}

	template<typename T>
	inline const T& FF::BoundedSphere<T>::GetLocation(void) const {
		return this->m_Location;
	}

	template<typename T>
	inline void FF::BoundedSphere<T>::SetRadius(const T& radius){
		this->m_Radius = radius;
	}

	template<typename T>
	inline const T& FF::BoundedSphere<T>::GetRadius(void) const {
		return this->m_Radius;
	}
};

#endif // FF_BOUNDEDSPHERE_HXX_