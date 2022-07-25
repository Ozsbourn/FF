#include <cmath>
#include <iostream>
 
#include "FF_Macros.hxx"
#include "FF_CommonMath.hxx"

#ifndef FF_VECTOR2_HXX_
#define FF_VECTOR2_HXX_

namespace FF {
	/**
	 * @brief [Class that represent two-dimensional vector]
	 * @details [Two-dimensional vector have a two components, that describe X and Y components,
	 * 			  and is used to describe something in 2D spaces]
	 * 
	 * @tparam T [Generic type]
	 */
	template<typename T>
	class Vector2 {
	private:
		T m_x;
		T m_y;
	public:
		/**
		 * @brief [Default constructor are not defined to all entities in FF]
		 */
		explicit Vector2(void) = delete;

		/**
		 * @brief [Constuctor with the parameters that have init VEC2 with scalar values for components]
		 * 
		 * @param x [X component]
		 * @param y [Y component]
		 */
		explicit Vector2( T __FF_IN x = static_cast<T>(0.0f), 
			  	  		  T __FF_IN y = static_cast<T>(0.0f) )
		: m_x(x), m_y(y) {}

		/**
		 * @brief [Copy constructor to VEC2]
		 * @details [Copy each component of VEC to this vector]
		 * 
		 * @param vec [Vector]
		 */
		explicit Vector2(FF::Vector2<T>& __FF_IN vec);


		/**
		 * @brief [Method that set X component of vector]
		 * 
		 * @param x [Value of X component]
		 */
		inline void 	SetXComponent(T __FF_IN x);
		/**
		 * @brief [Method that set Y component of vector]
		 * 
		 * @param y [Value of Y component]
		 */
		inline void 	SetYComponent(T __FF_IN y);


		/**
		 * @brief [Method that get X component of vector]
		 * @details [Const method]
		 * 
		 * @param y [Value of X component]
		 */
		const inline T& GetXComponent(void) const;
		/**
		 * @brief [Method that get Y component of vector]
		 * @details [Const method]
		 * 
		 * @param y [Value of Y component]
		 */
		const inline T& GetYComponent(void) const;


		/**
		 * @brief [Friend function that return -vec]
		 * @details [Apply '-' to each component]
		 * 
		 * @param vec [Vector]
		 * @tparam U [Generic type]
		 * @return [Return vector that represent origin vector with other sign]
		 */
		template<typename U>
		friend FF::Vector2<U> operator-(const FF::Vector2<U>& __FF_IN vec);

		/**
		 * @brief [Friend function that calculate difference of two vecs]
		 * @details [Each component is difference of appropriate components of parameter vectors]
		 * 
		 * @param vec1 [First vector]
		 * @param vec2 [Second vector]
		 * @tparam U [Generic type]
		 * @return [Return vectors that represent difference of two vectors]
		 */
		template<typename U>
		friend FF::Vector2<U> operator-(const FF::Vector2<U>& __FF_IN vec1, const FF::Vector2<U>& __FF_IN vec2);

		/**
		 * @brief [Friend function that calculate sum of two vector]
		 * @details [Each component is sum of appropriate components origin vectors]
		 * 
		 * @param vec [Vector]
		 * @tparam U [Generic type]
		 * @return [Return vector that represent sum of origin vectors]
		 */
		template<typename U>
		friend FF::Vector2<U> operator+(const FF::Vector2<U>& __FF_IN vec1, const FF::Vector2<U>& __FF_IN vec2);
		
		/**
		 * @brief [Friend function that calculate composition vec and scalar value]
		 * @details [Each component mul to scalar]
		 * 
		 * @param vec [Vector]
		 * @tparam U [Generic type]
		 * @return [Return vector that represent mul of origin vector and scalar value]
		 */
		template<typename U>
		friend FF::Vector2<U> operator*(const FF::Vector2<U>& __FF_IN vec,  const U& __FF_IN scalar);
		
		/**
		 * @brief [Friend function that calculate division vector and scalar value]
		 * @details [Each component divide to scalar]
		 * 
		 * @param vec [Vector]
		 * @tparam U [Generic type]
		 * @return [Return vector that represent div of origin vector and scalar value]
		 */
		template<typename U>
		friend FF::Vector2<U> operator/(const FF::Vector2<U>& __FF_IN vec,  const U& __FF_IN scalar);

		
		/**
		 * @brief [Operator that calculate dif with this vector and parameter vector]
		 * @details [-]
		 * 
		 * @param vec [Vector]
		 */
		inline void operator-=(const FF::Vector2<T>& __FF_IN vec);
		
		/**
		 * @brief [Operator that calculate sum with this vector and parameter vector]
		 * @details [-]
		 * 
		 * @param vec [Vector]
		 */
		inline void operator+=(const FF::Vector2<T>& __FF_IN vec);

		
		/**
		 * @brief [Operator that calculate difference of this vector and scalar]
		 * @details [-]
		 * 
		 * @param scalar [Scalar value]
		 */
		inline void operator-=(const T& __FF_IN scalar);
		
		/**
		 * @brief [Operator that calculate sum of this vector and scalar]
		 * @details [-]
		 * 
		 * @param scalar [Scalar value]
		 */
		inline void operator+=(const T& __FF_IN scalar);
		
		/**
		 * @brief [Operator that calculate mul of this vector and scalar]
		 * @details [-]
		 * 
		 * @param scalar [Scalar value]
		 */
		inline void operator*=(const T& __FF_IN scalar);
		
		/**
		 * @brief [Operator that calculate div of this vector and scalar]
		 * @details [-]
		 * 
		 * @param scalar [Scalar value]
		 */
		inline void operator/=(const T& __FF_IN scalar);

		/**
		 	* @brief [Method that return component of vector such as lvalue]
		 	* @details [-]
		 	* 
		 	* @param index [Index of component vector]
		 	* @return [Return component like a lvalue]
		 	*/
		const T& operator[](const std::size_t __FF_IN index);

		/**
		 * @brief [Friend function that calculate dot product of two vectors]
		 * @details [Dot product is sum of all mul appropriate components]
		 * 
		 * @param vec1 [First vector]
		 * @param vec2 [Second vector]
		 * @tparam U [Generic type]
		 * @return [Return value that represent result of dot product]
		 */
		template<typename U>
		friend inline U      	      DotProduct(const FF::Vector2<U>& __FF_IN vec1, const FF::Vector2<U>& __FF_IN vec2);


		/**
		 * @brief [Method that find project vector VEC1 on vector VEC2]
		 * @details [Method calculate vector project VEC1 on VEC2]
		 * 
		 * @param vec1 [First vector]
		 * @param vec2 [Second vector]
		 * @tparam T [Generic type]
		 * @return [Return the project of vector]
		 */
		template<typename U>
		friend inline FF::Vector2<U>  Project(const FF::Vector2<U>& __FF_IN vec1, const FF::Vector2<U>& __FF_IN vec2);

		/**
		 * @brief [Method that find reject vectors VEC1 and VEC2]
		 * @details [Method calculate reject vector VEC1 from VEC2]
		 * 
		 * @param vec1 [First vector]
		 * @param vec2 [Second vector]
		 * @tparam T [Generic type]
		 * @return [Return reject of vectors]
		 */
		template<typename U>
		friend inline FF::Vector2<U>  Reject(const FF::Vector2<U>& __FF_IN vec1, const FF::Vector2<U>& __FF_IN vec2);


		/**
		 * @brief [Method that calculate magnitude of vector]
		 * @details [Method find and return square root of sum of squares of each component of vector]
		 * 
		 * @param vec [Vector]
		 * @tparam T [Generic type]
		 * @return [Return the magnitude of vector]
		 */
		template<typename U>
		friend inline U   	         Magnitude(const FF::Vector2<U>& __FF_IN vec);

		/**
		 * @brief [Method that find square of magnitude of vector]
		 * @details [Method find and return sum of squares of each component of vector]
		 * 
		 * @param vec [Vector]
		 * @tparam T [Generic type]
		 * @return [Return sqaured magnitude of vector]
		 */
		template<typename U>
		friend inline U   	      SquaredMagnitude(const FF::Vector2<U>& __FF_IN vec);


		/**
	 	 * @brief [Method that that instance the origin vector after normalize]
	 	 * @details [Method normalize a vector: subdivide each component on magnitude of this vector]
	 	 * 
	 	 * @param vec [Vector]
	 	 * @tparam T [Generic type]
	 	 * @return [Return the copy of origin vector that was normalize]
	 	 */
		template<typename U>
		friend inline FF::Vector2<U> Normalize(const FF::Vector2<U>& __FF_IN vec);

		/**
		 * @brief [Default destructor]
		 * @details [-]
		 */
		~Vector2(void) = default;


		/**
		 * @brief [Debug override << operator]
		 * @details [Used for output values in ostream. Friend function]
		 * 
		 * @param out [Out stream]
		 * @param vec [Vector]
		 */
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

	
	template<typename T>
	const T&  FF::Vector2<T>::operator[](const std::size_t __FF_IN index){
		FF_ASSERT_MESSAGE(index < 0x2uL, "Going beyond the vector");
		return *(&(this->m_x) + index);
	}

	template<typename T>
	inline T DotProduct(const FF::Vector2<T>& __FF_IN vec1, const FF::Vector2<T>& __FF_IN vec2){
		return (vec1.m_x * vec2.m_x + vec1.m_y * vec2.m_y);
	}

	template<typename T>
	inline FF::Vector2<T> Project(const FF::Vector2<T>& __FF_IN vec1, const FF::Vector2<T>& __FF_IN vec2){
		return (vec2 * DotProduct(vec1, vec2) / DotProduct(vec2, vec2));
	}

	template<typename T>
	inline FF::Vector2<T> Reject(const FF::Vector2<T>& __FF_IN vec1, const FF::Vector2<T>& __FF_IN vec2){
		return (vec1 - vec2 * DotProduct(vec1, vec2) / DotProduct(vec2, vec2));
	}

	template<typename T>
	inline T Magnitude(const FF::Vector2<T>& __FF_IN vec){	
		return sqrt(FF::sqr(vec.m_x) + FF::sqr(vec.m_y));
	}


	template<typename T>
	inline T SquaredMagnitude(const FF::Vector2<T>& __FF_IN vec){
		return ( FF::sqr(vec.m_x) + FF::sqr(vec.m_y) );
	}

	template<typename T>
	inline FF::Vector2<T> Normalize(const FF::Vector2<T>& __FF_IN vec){
		return (vec / FF::Magnitude(vec));
	}

	template<typename T>
	std::ostream& operator<< (std::ostream& __FF_IN out, FF::Vector2<T>& __FF_IN vec){
		std::cout << "{" << vec.m_x << ", " << vec.m_y << "}" << std::endl;
		return out;
	}
};

#endif // FF_VECTOR2_HXX_