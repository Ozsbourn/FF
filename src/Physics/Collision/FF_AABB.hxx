#include "..\..\Core\FF_Vector3.hxx"

#ifndef FF_AABB_HXX_
#define FF_AABB_HXX_

namespace FF {
	template<typename T>
	class AABB {
	private:
		FF::Vector3<T> m_BottomBound;						// Height and Width
		FF::Vector3<T> m_TopBound;							// Depth
	public:
		explicit AABB(void) = delete;

		explicit AABB( FF::Vector3<T>& __FF_IN vec1,
					   FF::Vector3<T>& __FF_IN vec2 ) 
		: m_BottomBound(vec1), m_TopBound(vec2) {}

		explicit AABB(FF::AABB<T> box);

		inline FF::Vector3<T>& GetBottomBound(void) const;
		inline FF::Vector3<T>& GetTopBound(void) const;

		inline void SetBottomBound(FF::Vector3<T>& __FF_IN vec);
		inline void SetTopBound(FF::Vector3<T>& __FF_IN vec);	

		~AABB(void) = default;	
	};

	template<typename T>
	FF::AABB<T>::AABB(FF::AABB<T> box) {
		this->m_BottomBound = box.GetBottomBound();
		this->m_TopBound    = box.GetTopBound();
	}

	template<typename T>
	inline FF::Vector3<T>& FF::AABB<T>::GetBottomBound(void) const {
		return this->m_BottomBound;
	}

	template<typename T>
	inline FF::Vector3<T>& FF::AABB<T>::GetTopBound(void) const {
		return this->m_TopBound;
	}

	template<typename T>
	inline void FF::AABB<T>::SetBottomBound(FF::Vector3<T>& __FF_IN vec){
		this->m_BottomBound = vec;
	}

	template<typename T>
	inline void FF::AABB<T>::SetTopBound(FF::Vector3<T>& __FF_IN vec){
		this->m_TopBound = vec;
	}
};

#endif // FF_AABB_HXX_