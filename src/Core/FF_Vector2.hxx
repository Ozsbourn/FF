#include <cmath>
#include <iostream>
 
#include "FF_Macros.hxx"
#include "FF_CommonMath.hxx"

#ifndef FF_VECTOR2_HXX_
#define FF_VECTOR2_HXX_

namespace FF {
	template<typename T>
	class Vector2 {
	private:
		T m_x;
		T m_y;
	public:
		explicit Vector2(void) = delete;

		explicit Vector2( T __FF_IN x = static_cast<T>(0.0f), 
			  	  		  T __FF_IN y = static_cast<T>(0.0f) )
		: m_x(x), m_y(y) {};

		explicit Vector2(FF::Vector2<T>& __FF_IN vec);

		inline void 	SetXComponent(T __FF_IN x);
		inline void 	SetYComponent(T __FF_IN y);

		const inline T& GetXComponent(void) const;
		const inline T& GetYComponent(void) const;

		template<typename U>
		friend FF::Vector2<U> operator-(const FF::Vector2<U>& __FF_IN vec);
		template<typename U>
		friend FF::Vector2<U> operator-(const FF::Vector2<U>& __FF_IN vec1, const FF::Vector2<U>& __FF_IN vec2);
		template<typename U>
		friend FF::Vector2<U> operator+(const FF::Vector2<U>& __FF_IN vec1, const FF::Vector2<U>& __FF_IN vec2);
		template<typename U>
		friend FF::Vector2<U> operator*(const FF::Vector2<U>& __FF_IN vec,  const U& __FF_IN scalar);
		template<typename U>
		friend FF::Vector2<U> operator/(const FF::Vector2<U>& __FF_IN vec,  const U& __FF_IN scalar);

		inline void operator-=(const FF::Vector2<T>& __FF_IN vec);
		inline void operator+=(const FF::Vector2<T>& __FF_IN vec);

		inline void operator-=(const T& __FF_IN scalar);
		inline void operator+=(const T& __FF_IN scalar);
		inline void operator*=(const T& __FF_IN scalar);
		inline void operator/=(const T& __FF_IN scalar);

		const T& operator[](const std::size_t __FF_IN index);

		template<typename U>
		friend inline U      	      DotProduct(const FF::Vector2<U>& __FF_IN vec1, const FF::Vector2<U>& __FF_IN vec2);
		/*template<typename U>
		friend inline FF::Vector2<U>& CrossProduct(const FF::Vector2<U>& __FF_IN vec1, const FF::Vector2<U>& __FF_IN vec2);*/

		template<typename U>
		friend inline FF::Vector2<U>  Project(const FF::Vector2<U>& __FF_IN vec1, const FF::Vector2<U>& __FF_IN vec2);
		template<typename U>
		friend inline FF::Vector2<U>  Reject(const FF::Vector2<U>& __FF_IN vec1, const FF::Vector2<U>& __FF_IN vec2);

		template<typename U>
		friend inline U   	         Magnitude(const FF::Vector2<U>& __FF_IN vec);
		template<typename U>
		friend inline U   	      SquaredMagnitude(const FF::Vector2<U>& __FF_IN vec);
		template<typename U>
		friend inline FF::Vector2<U> Normalize(const FF::Vector2<U>& __FF_IN vec);

		~Vector2(void) = default;

		template<typename U>
		friend inline std::ostream& operator<< (std::ostream& __FF_IN out, Vector2<U>& __FF_IN vec);
	};

	template<typename T>
	FF::Vector2<T>::Vector2(FF::Vector2<T>& __FF_IN vec) {
		this->m_x = vec.GetXComponent();
		this->m_y = vec.GetYComponent();
	}

	template<typename T>
	inline void FF::Vector2<T>::SetXComponent(T __FF_IN x) {
		this->m_x = x;
	}

	template<typename T>
	inline void FF::Vector2<T>::SetYComponent(T __FF_IN y) {
		this->m_y = y;
	}

	template<typename T>
	const inline T& FF::Vector2<T>::GetXComponent(void) const {
		return m_x;
	}

	template<typename T>
	const inline T& FF::Vector2<T>::GetYComponent(void) const {
		return m_y;
	}

	template<typename T>
	FF::Vector2<T> operator-(const FF::Vector2<T>& __FF_IN vec){
		return FF::Vector2<T>(-vec.m_x, -vec.m_y);
	}

	template<typename T>
	FF::Vector2<T> operator-(const FF::Vector2<T>& __FF_IN vec1, const FF::Vector2<T>& __FF_IN vec2){
		return FF::Vector2<T>( vec1.m_x - vec2.m_x,
					 		   vec1.m_y - vec2.m_y );
	}
		
	template<typename T>
	FF::Vector2<T> operator+(const FF::Vector2<T>& __FF_IN vec1, const FF::Vector2<T>& __FF_IN vec2){
		return FF::Vector2<T>( vec1.m_x + vec2.m_x,
					 		   vec1.m_y + vec2.m_y );
	}
		
	template<typename T>
	FF::Vector2<T> operator*(const FF::Vector2<T>& __FF_IN vec, const T& __FF_IN scalar){
		return FF::Vector2<T>( vec.m_x * scalar,
					 		   vec.m_y * scalar );
	}
		
	template<typename T>
	FF::Vector2<T> operator/(const FF::Vector2<T>& __FF_IN vec, const T& __FF_IN scalar){
		return FF::Vector2<T>( vec.m_x / scalar,
					 		   vec.m_y / scalar );
	}

	template<typename T>
	inline void FF::Vector2<T>::operator-=(const FF::Vector2<T>& __FF_IN vec){
		this->m_x -= vec.GetXComponent();
		this->m_x -= vec.GetYComponent();
	}

	template<typename T>
	inline void FF::Vector2<T>::operator+=(const FF::Vector2<T>& __FF_IN vec){
		this->m_x += vec.GetXComponent();
		this->m_x += vec.GetYComponent();
	}

	template<typename T>
	inline void FF::Vector2<T>::operator-=(const T& __FF_IN scalar){
		this->m_x -= scalar;
		this->m_y -= scalar;
	}

	template<typename T>
	inline void FF::Vector2<T>::operator+=(const T& __FF_IN scalar){
		this->m_x += scalar;
		this->m_y += scalar;
	}

	template<typename T>
	inline void FF::Vector2<T>::operator*=(const T& __FF_IN scalar){
		this->m_x *= scalar;
		this->m_y *= scalar;
	}

	template<typename T>
	inline void FF::Vector2<T>::operator/=(const T& __FF_IN scalar){
		this->m_x /= scalar;
		this->m_y /= scalar;
	}

	/**
	 * @brief [Method that return component of vector such as lvalue]
	 * @details [-]
	 * 
	 * @param index [Index of component vector]
	 * @return [Return component like a lvalue]
	 */
	template<typename T>
	const T&  FF::Vector2<T>::operator[](const std::size_t __FF_IN index){
		FF_ASSERT_MESSAGE(index < 0x2uL, "Going beyond the vector");
		return *(&(this->m_x) + index);
	}

	/**
	 * @brief [Methods that represent dot product of two vectors]
	 * @details [Method find and return the sum of the products of each component of two vectors]
	 * 
	 * @param vec1 [first vector]
	 * @param vec2 [second vector]
	 * @tparam T [Generic type]
	 * @return [The result of dot product]
	 */
	template<typename T>
	inline T DotProduct(const FF::Vector2<T>& __FF_IN vec1, const FF::Vector2<T>& __FF_IN vec2){
		return (vec1.m_x * vec2.m_x + vec1.m_y * vec2.m_y);
	}

	/*template<typename T>
	inline FF::Vector2<T>& CrossProduct(const FF::Vector2<T>& __FF_IN vec1, const FF::Vector2<T>& __FF_IN vec2){

	}*/

	/**
	 * @brief [Method that find project vector VEC1 on vector VEC2]
	 * @details [Method calculate vector project VEC1 on VEC2]
	 * 
	 * @param vec1 [First vector]
	 * @param vec2 [Second vector]
	 * @tparam T [Generic type]
	 * @return [Return the project of vector]
	 */
	template<typename T>
	inline FF::Vector2<T> Project(const FF::Vector2<T>& __FF_IN vec1, const FF::Vector2<T>& __FF_IN vec2){
		return (vec2 * DotProduct(vec1, vec2) / DotProduct(vec2, vec2));
	}

	/**
	 * @brief [Method that find reject vectors VEC1 and VEC2]
	 * @details [Method calculate reject vector VEC1 from VEC2]
	 * 
	 * @param vec1 [First vector]
	 * @param vec2 [Second vector]
	 * @tparam T [Generic type]
	 * @return [Return reject of vectors]
	 */
	template<typename T>
	inline FF::Vector2<T> Reject(const FF::Vector2<T>& __FF_IN vec1, const FF::Vector2<T>& __FF_IN vec2){
		return (vec1 - vec2 * DotProduct(vec1, vec2) / DotProduct(vec2, vec2));
	}

	/**
	 * @brief [Method that calculate magnitude of vector]
	 * @details [Method find and return square root of sum of squares of each component of vector]
	 * 
	 * @param vec [Vector]
	 * @tparam T [Generic type]
	 * @return [Return the magnitude of vector]
	 */
	template<typename T>
	inline T Magnitude(const FF::Vector2<T>& __FF_IN vec){	
		return sqrt(FF::sqr(vec.m_x) + FF::sqr(vec.m_y));
	}

	/**
	 * @brief [Method that find square of magnitude of vector]
	 * @details [Method find and return sum of squares of each component of vector]
	 * 
	 * @param vec [Vector]
	 * @tparam T [Generic type]
	 * @return [Return sqaured magnitude of vector]
	 */
	template<typename T>
	inline T SquaredMagnitude(const FF::Vector2<T>& __FF_IN vec){
		return ( FF::sqr(vec.m_x) + FF::sqr(vec.m_y) );
	}

	/**
	 * @brief [Method that that instance the origin vector after normalize]
	 * @details [Method normalize a vector: subdivide each component on magnitude of this vector]
	 * 
	 * @param vec [Vector]
	 * @tparam T [Generic type]
	 * @return [Return the copy of origin vector that was normalize]
	 */
	template<typename T>
	inline FF::Vector2<T> Normalize(const FF::Vector2<T>& __FF_IN vec){
		return (vec / FF::Magnitude(vec));
	}

	/**
	 * @brief [Override method that push in out stream vector]
	 * @details [-]
	 * 
	 * @param out [Output stream]
	 * @param vec [Vector]
	 * @tparam T [Generic type]
	 * @return [Return the reference on output stream]
	 */
	template<typename T>
	std::ostream& operator<< (std::ostream& __FF_IN out, FF::Vector2<T>& __FF_IN vec){
		std::cout << "{" << vec.m_x << ", " << vec.m_y << "}" << std::endl;
		return out;
	}
};

#endif // FF_VECTOR2_HXX_