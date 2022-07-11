#include <cmath>
#include <cassert>
#include <iostream>

#include "FF_Macros.hxx"
#include "FF_CommonMath.hxx"

#ifndef FF_VECTOR4_HXX_
#define FF_VECTOR4_HXX_

namespace FF {
	template<typename T>
	class Vector4 {
	private:
		T m_x;
		T m_y;
		T m_z;
		T m_w;
	public:
		explicit Vector4(void) = delete;

		explicit Vector4( T __FF_IN x = static_cast<T>(0.0f), 
						  T __FF_IN y = static_cast<T>(0.0f),
						  T __FF_IN z = static_cast<T>(0.0f),
						  T __FF_IN w = static_cast<T>(0.0f) )
		: m_x(x), m_y(y), m_z(z), m_w(w) {};

		explicit Vector4(FF::Vector4<T>& __FF_IN vec);

		inline void SetXComponent(T __FF_IN x);
		inline void SetYComponent(T __FF_IN y);
		inline void SetZComponent(T __FF_IN z);
		inline void SetWComponent(T __FF_IN w);

		const inline T& GetXComponent(void) const;
		const inline T& GetYComponent(void) const;
		const inline T& GetZComponent(void) const;
		const inline T& GetWComponent(void) const;

		template<typename U>
		friend FF::Vector4<U> operator-(const FF::Vector4<U>& __FF_IN vec);
		template<typename U>
		friend FF::Vector4<U> operator-(const FF::Vector4<U>& __FF_IN vec1, const FF::Vector4<U>& __FF_IN vec2);
		template<typename U>
		friend FF::Vector4<U> operator+(const FF::Vector4<U>& __FF_IN vec1, const FF::Vector4<U>& __FF_IN vec2);
		template<typename U>
		friend FF::Vector4<U> operator*(const FF::Vector4<U>& __FF_IN vec,  const U& __FF_IN scalar);
		template<typename U>
		friend FF::Vector4<U> operator/(const FF::Vector4<U>& __FF_IN vec,  const U& __FF_IN scalar);

		inline void operator-=(const T& __FF_IN scalar);
		inline void operator+=(const T& __FF_IN scalar);
		inline void operator*=(const T& __FF_IN scalar);
		inline void operator/=(const T& __FF_IN scalar);

		const T& operator[](std::size_t __FF_IN index);

		template<typename U>
		friend inline U     	 	  DotProduct(const FF::Vector4<U>& __FF_IN vec1, const FF::Vector4<U>& __FF_IN vec2);
		/*template<typename U>
		friend inline FF::Vector4<U>& CrossProduct(const FF::Vector4<U>& __FF_IN vec1, const FF::Vector4<U>& __FF_IN vec2);*/

		template<typename U>
		friend inline FF::Vector4<U>& Project(const FF::Vector4<U>& __FF_IN vec1, const FF::Vector4<U>& __FF_IN vec2);
		template<typename U>
		friend inline FF::Vector4<U>& Reject(const FF::Vector4<U>& __FF_IN vec1,  const FF::Vector4<U>& __FF_IN vec2);

		template<typename U>
		friend inline U           	  Magnitude(const FF::Vector4<U>& __FF_IN vec);
		template<typename U>
		friend inline U   	      	  SquaredMagnitude(const FF::Vector4<U>& __FF_IN vec);
		template<typename U>
		friend inline FF::Vector4<U>& Normalize(const FF::Vector4<U>& __FF_IN vec);

		~Vector4(void) = default;

		template<typename U>
		friend inline std::ostream& operator<< (std::ostream& __FF_IN out, Vector4<T>& __FF_IN vec);
	};

	template<typename T>
	FF::Vector4<T>::Vector4(FF::Vector4<T>& __FF_IN vec) {
		this->m_x = vec.GetXComponent();
		this->m_y = vec.GetYComponent();
		this->m_z = vec.GetZComponent();
		this->m_w = vec.GetWComponent();
	}

	template<typename T>
	inline void FF::Vector4<T>::SetXComponent(T __FF_IN x) {
		this->m_x = x;
	}

	template<typename T>
	inline void FF::Vector4<T>::SetYComponent(T __FF_IN y) {
		this->m_y = y;
	}

	template<typename T>
	inline void FF::Vector4<T>::SetZComponent(T __FF_IN z) {
		this->m_z = z;
	}

	template<typename T>
	inline void FF::Vector4<T>::SetWComponent(T __FF_IN w) {
		this->m_w = w;
	}

	template<typename T>
	const inline T& FF::Vector4<T>::GetXComponent(void) const {
		return m_x;
	}

	template<typename T>
	const inline T& FF::Vector4<T>::GetYComponent(void) const {
		return m_y;
	}

	template<typename T>
	const inline T& FF::Vector4<T>::GetZComponent(void) const {
		return m_z;
	}

	template<typename T>
	const inline T& FF::Vector4<T>::GetWComponent(void) const {
		return m_w;
	}

	template<typename T>
	FF::Vector4<T> operator-(const FF::Vector4<T>& __FF_IN vec){
		return FF::Vector4<T>(-vec.m_x, -vec.m_y, -vec.m_z, -vec.m_w);
	}

	template<typename T>
	FF::Vector4<T> operator-(const FF::Vector4<T>& __FF_IN vec1, const FF::Vector4<T>& __FF_IN vec2){
		return FF::Vector4<T>( vec1.m_x - vec2.m_x,
							   vec1.m_y - vec2.m_y,
							   vec1.m_z - vec2.m_z,
							   vec1.m_w - vec2.m_w );
	}
		
	template<typename T>
	FF::Vector4<T> operator+(const FF::Vector4<T>& __FF_IN vec1, const FF::Vector4<T>& __FF_IN vec2){
		return FF::Vector4<T>( vec1.m_x + vec2.m_x,
							   vec1.m_y + vec2.m_y,
							   vec1.m_z + vec2.m_z,
							   vec1.m_w + vec2.m_w );
	}
		
	template<typename T>
	FF::Vector4<T> operator*(const FF::Vector4<T>& __FF_IN vec,  const T& __FF_IN scalar){
		return FF::Vector4<T>( vec.m_x * scalar,
					 		   vec.m_y * scalar,
					 		   vec.m_z * scalar,
					 		   vec.m_w * scalar );
	}
		
	template<typename T>
	FF::Vector4<T> operator/(const FF::Vector4<T>& __FF_IN vec,  const T& __FF_IN scalar){
		return FF::Vector4<T>( vec.m_x / scalar,
					 		   vec.m_y / scalar,
					 		   vec.m_z / scalar,
					 		   vec.m_w / scalar );
	}

	template<typename T>
	inline void FF::Vector4<T>::operator-=(const T& __FF_IN scalar){
		this->m_x -= scalar;
		this->m_y -= scalar;
		this->m_z -= scalar;
		this->m_w -= scalar;
	}

	template<typename T>
	inline void FF::Vector4<T>::operator+=(const T& __FF_IN scalar){
		this->m_x += scalar;
		this->m_y += scalar;
		this->m_z += scalar;
		this->m_w += scalar;
	}

	template<typename T>
	inline void FF::Vector4<T>::operator*=(const T& __FF_IN scalar){
		this->m_x *= scalar;
		this->m_y *= scalar;
		this->m_y *= scalar;
		this->m_w *= scalar;
	}

	template<typename T>
	inline void FF::Vector4<T>::operator/=(const T& __FF_IN scalar){
		this->m_x /= scalar;
		this->m_y /= scalar;
		this->m_y /= scalar;
		this->m_w /= scalar;
	}

	template<typename T>
	const T& FF::Vector4<T>::operator[](std::size_t __FF_IN index){
		FF_ASSERT_MESSAGE(index < 0x4uL, "Going beyond the vector");
		return *(&(this->m_x) + index);
	}

	template<typename T>
	inline T DotProduct(const FF::Vector4<T>& __FF_IN vec1, const FF::Vector4<T>& __FF_IN vec2){
		return (vec1.m_x * vec2.m_x + vec1.m_y * vec2.m_y + vec1.m_z * vec2.m_z + vec1.m_w * vec2.m_w);
	}

	template<typename T>
	inline FF::Vector4<T>& Project(const FF::Vector4<T>& __FF_IN vec1, const FF::Vector4<T>& __FF_IN vec2){
		return (vec2 * DotProduct(vec1, vec2) / DotProduct(vec2, vec2));
	}

	template<typename T>
	inline FF::Vector4<T>& Reject(const FF::Vector4<T>& __FF_IN vec1, const FF::Vector4<T>& __FF_IN vec2){
		return (vec1 - vec2 * DotProduct(vec1, vec2) / DotProduct(vec2, vec2));
	}

	template<typename T>
	inline T Magnitude(const FF::Vector4<T>& __FF_IN vec){	
		return sqrt( FF::sqr(vec.m_x) + 
					 FF::sqr(vec.m_y) + 
					 FF::sqr(vec.m_z) + 
					 FF::sqr(vec.m_w) );
	}

	template<typename T>
	inline T SquaredMagnitude(const Vector4<T>& __FF_IN vec){
		return ( FF::sqr(vec.m_x) + 
				 FF::sqr(vec.m_y) + 
				 FF::sqr(vec.m_z) +
				 FF::sqr(vec.m_w) );
	}

	template<typename T>
	inline FF::Vector4<T>& Normalize(const FF::Vector4<T>& __FF_IN vec){
		return (vec / Magnitude(vec));
	}

	// debug
	template<typename T>
	std::ostream& operator<< (std::ostream& __FF_IN out, Vector4<T>& __FF_IN vec){
		std::cout << "{" << vec.m_x << ", " << vec.m_y << "," << vec.m_z << "," << vec.m_w << "}" << std::endl;
		return out;
	}
};

#endif // FF_VECTOR4_HXX_