#include "..\Core\FF_Vector3.hxx"

#ifndef FF_FORCE_HXX_
#define FF_FORCE_HXX_

namespace FF {
	template<typename T>
	class Force {
	private:
		FF::Vector3<T> m_Direction;
		FF::Vector3<T> m_Location;
	public:
		explicit Force(void) = delete;

		explicit Force( T v11 = static_cast<T>(0.0f), v12 = static_cast<T>(0.0f), v13 = static_cast<T>(0.0f),
				 		  v21 = static_cast<T>(0.0f), v22 = static_cast<T>(0.0f), v23 = static_cast<T>(0.0f) )
		: m_Direction{v11, v12, v13}, m_Location{v21, v22, v23} {}

		explicit Force( FF::Vector3<T> vec1,
			            FF::Vector3<T> vec2 );

		inline FF::Vector3<T> GetLocation(void) const;
		inline void 		  SetLocation(const FF::Vector3<T>& __FF_IN location);

		inline FF::Vector3<T> GetDirection(void) const;
		inline void 		  SetDirection(const FF::Vector3<T>& __FF_IN direction);

		~Force(void);
	};

	template<typename T>
	FF::Force<T>::Force( FF::Vector3<T> vec1,
			             FF::Vector3<T> vec2 ){
		this->m_Direction = vec1;
		this->m_Location  = vec2;
	}

	template<typename T>
	inline FF::Vector3<T> GetLocation(void) const {
		return this->m_Location;
	}

	template<typename T>
	inline void 		  SetLocation(const FF::Vector3<T>& __FF_IN location){
		this->m_Location = location;
	}

	template<typename T>
	inline FF::Vector3<T> GetDirection(void) const {
		return this->m_Direction;
	}

	template<typename T>
	inline void 		  SetDirection(const FF::Vector3<T>& __FF_IN direction){
		this->m_Direction = direction;
	}
};

#endif // FF_FORCE_HXX_