#include <cmath>
#include <iostream>

#include "FF_Macros.hxx"
#include "FF_CommonMath.hxx"

#ifndef FF_VECTOR4_HXX_
#define FF_VECTOR4_HXX_

namespace FF {
	/**
	 * @brief   [Class that represent four-dimensional vector]
	 * @details [Four-dimensional vector have a two components, that describe X and Y components,
	 * 			  and is used to describe something in 3D and 4D spaces]
	 * 
	 * @tparam T [Generic type]
	 */
	template<typename T>
	class Vector4 {
	private:
		T m_x;
		T m_y;
		T m_z;
		T m_w;
	public:
		/**
		 * @brief [Default constructor are not defined to all entities in FF]
		 */
		explicit Vector4(void) = delete;

		/**
		 * @brief [Constuctor with the parameters that have init VEC2 with scalar values for components]
		 * 
		 * @param x [X component]
		 * @param y [Y component]
		 */
		explicit Vector4( const T __FF_IN x = static_cast<T>(0.0f), 
						  const T __FF_IN y = static_cast<T>(0.0f),
						  const T __FF_IN z = static_cast<T>(0.0f),
						  const T __FF_IN w = static_cast<T>(0.0f) )
		: m_x(x), m_y(y), m_z(z), m_w(w) {};

		/**
		 * @brief [Copy constructor to VEC4]
		 * @details [Copy each component of VEC to this vector]
		 * 
		 * @param vec [Vector]
		 */
		explicit Vector4(FF::Vector4<T>& __FF_IN vec);



		/**
		 * @brief [Method that set X component of vector]
		 * 
		 * @param x [Value of X component]
		 */
		inline void SetXComponent(T __FF_IN x) noexcept;

		/**
		 * @brief [Method that set Y component of vector]
		 * 
		 * @param x [Value of Y component]
		 */
		inline void SetYComponent(T __FF_IN y) noexcept;

		/**
		 * @brief [Method that set Z component of vector]
		 * 
		 * @param x [Value of Z component]
		 */
		inline void SetZComponent(T __FF_IN z) noexcept;

		/**
		 * @brief [Method that set W component of vector]
		 * 
		 * @param x [Value of W component]
		 */
		inline void SetWComponent(T __FF_IN w) noexcept;

		/**
		 * @brief [Method that set X, Y, Z and W component]
		 * 
		 * @param x [X component]
		 * @param y [Y component]
		 * @param z [Z component]
		 * @param w [W component]
		 */
		inline void SetXYZW(const T __FF_IN x, const T __FF_IN y, const T __FF_IN z, const T __FF_IN w) noexcept;



		/**
		 * @brief [Method that get X component of vector]
		 * @details [Const method]
		 * 
		 * @param y [Value of X component]
		 */
		const inline T& GetXComponent(void) const noexcept;

		/**
		 * @brief [Method that get Y component of vector]
		 * @details [Const method]
		 * 
		 * @param y [Value of Y component]
		 */
		const inline T& GetYComponent(void) const noexcept;

		/**
		 * @brief [Method that get Z component of vector]
		 * @details [Const method]
		 * 
		 * @param y [Value of Z component]
		 */
		const inline T& GetZComponent(void) const noexcept;

		/**
		 * @brief [Method that get W component of vector]
		 * @details [Const method]
		 * 
		 * @param y [Value of W component]
		 */
		const inline T& GetWComponent(void) const noexcept;



		/**
		 * @brief [Friend function that return -vec]
		 * @details [Apply '-' to each component]
		 * 
		 * @param vec [Vector]
		 * @tparam U [Generic type]
		 * @return [Return vector that represent origin vector with other sign]
		 */
		template<typename U>
		friend FF::Vector4<U> operator-(const FF::Vector4<U>& __FF_IN vec);

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
		friend FF::Vector4<U> operator-(const FF::Vector4<U>& __FF_IN vec1, const FF::Vector4<U>& __FF_IN vec2);

		/**
		 * @brief [Friend function that calculate sum of two vector]
		 * @details [Each component is sum of appropriate components origin vectors]
		 * 
		 * @param vec [Vector]
		 * @tparam U [Generic type]
		 * @return [Return vector that represent sum of origin vectors]
		 */
		template<typename U>
		friend FF::Vector4<U> operator+(const FF::Vector4<U>& __FF_IN vec1, const FF::Vector4<U>& __FF_IN vec2);

		/**
		 * @brief [Friend function that calculate composition vec and scalar value]
		 * @details [Each component mul to scalar]
		 * 
		 * @param vec [Vector]
		 * @tparam U [Generic type]
		 * @return [Return vector that represent mul of origin vector and scalar value]
		 */
		template<typename U>
		friend FF::Vector4<U> operator*(const FF::Vector4<U>& __FF_IN vec,  const U& __FF_IN scalar);

		/**
		 * @brief [Friend function that calculate division vector and scalar value]
		 * @details [Each component divide to scalar]
		 * 
		 * @param vec [Vector]
		 * @tparam U [Generic type]
		 * @return [Return vector that represent div of origin vector and scalar value]
		 */
		template<typename U>
		friend FF::Vector4<U> operator/(const FF::Vector4<U>& __FF_IN vec,  const U& __FF_IN scalar);



		/**
		 * @brief [Operator that calculate dif with this vector and parameter vector]
		 * @details [-]
		 * 
		 * @param vec [Vector]
		 */
		inline void operator-=(const FF::Vector4<T>& __FF_IN vec) noexcept;
		
		/**
		 * @brief [Operator that calculate sum with this vector and parameter vector]
		 * @details [-]
		 * 
		 * @param vec [Vector]
		 */
		inline void operator+=(const FF::Vector4<T>& __FF_IN vec) noexcept;



		/**
		 * @brief [Operator that calculate difference of this vector and scalar]
		 * @details [-]
		 * 
		 * @param scalar [Scalar value]
		 */
		inline void operator-=(const T& __FF_IN scalar) noexcept;

		/**
		 * @brief [Operator that calculate sum of this vector and scalar]
		 * @details [-]
		 * 
		 * @param scalar [Scalar value]
		 */
		inline void operator+=(const T& __FF_IN scalar) noexcept;

		/**
		 * @brief [Operator that calculate mul of this vector and scalar]
		 * @details [-]
		 * 
		 * @param scalar [Scalar value]
		 */
		inline void operator*=(const T& __FF_IN scalar) noexcept;

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
		const T& operator[](std::size_t __FF_IN index);



		/**
		 * @brief [Friend function that calculate dot product of two vectors]
		 * @details [Dot product is sum of all mul appropriate components. Member function]
		 * 
		 * @param this [This vector]
		 * @param vec  [Another vector]
		 * @tparam U   [Generic type]
		 * @return     [Return value that represent result of dot product this and parameter vector]
		 */
		inline T     	 	          DotProduct(const FF::Vector4<T>& __FF_IN vec) const noexcept;

		/**
		 * @brief [Friend function that calculate dot product of two vectors]
		 * @details [Dot product is sum of all mul appropriate components. Friend function]
		 * 
		 * @param vec1 [First vector]
		 * @param vec2 [Second vector]
		 * @tparam U [Generic type]
		 * @return [Return value that represent result of dot product parameter vectors]
		 */
		template<typename U>
		friend inline U     	 	  DotProduct(const FF::Vector4<U>& __FF_IN vec1, const FF::Vector4<U>& __FF_IN vec2);



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
		friend inline FF::Vector4<U>& Project(const FF::Vector4<U>& __FF_IN vec1, const FF::Vector4<U>& __FF_IN vec2);

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
		friend inline FF::Vector4<U>& Reject(const  FF::Vector4<U>& __FF_IN vec1, const FF::Vector4<U>& __FF_IN vec2);



        /**
		 * @brief   [Method that calculate magnitude of vector]
		 * @details [Method find and return square root of sum of squares of each component of vector. Member function]
		 * 
		 * @tparam T  [Generic type]
		 * @return    [Return the magnitude of this vector]
		 */
		inline T                      Magnitude(void) const noexcept;

		/**
		 * @brief   [Method that calculate magnitude of vector]
		 * @details [Method find and return square root of sum of squares of each component of vector. Friend function]
		 * 
		 * @param vec [Vector]
		 * @tparam U  [Generic type]
		 * @return    [Return the magnitude of parameter vector]
		 */
		template<typename U>
		friend inline U           	  Magnitude(const FF::Vector4<U>& __FF_IN vec);

		/**
		 * @brief [Method that find square of magnitude of vector]
		 * @details [Method find and return sum of squares of each component of vector. Friend function]
		 * 
		 * @tparam T  [Generic type]
		 * @return    [Return squared magnitude of this vector]
		 */
		inline T   	      	          SquaredMagnitude(void) const noexcept;

		/**
		 * @brief [Method that find square of magnitude of vector]
		 * @details [Method find and return sum of squares of each component of vector. Friend function]
		 * 
		 * @param vec [Vector]
		 * @tparam U  [Generic type]
		 * @return    [Return squared magnitude of parameter vector]
		 */
		template<typename U>
		friend inline U   	      	  SquaredMagnitude(const FF::Vector4<U>& __FF_IN vec);



		/**
	 	 * @brief   [Method that that instance the origin vector after normalize]
	 	 * @details [Method normalize a vector: subdivide each component on magnitude of this vector]
	 	 * 
	 	 * @tparam T  [Generic type]
	 	 * @return    [Return the copy of this vector that was normalize]
	 	 */		
		inline FF::Vector4<T> Normalize(void) const;

		/**
	 	 * @brief   [Method that that instance the origin vector after normalize]
	 	 * @details [Method normalize a vector: subdivide each component on magnitude of this vector. Friend function]
	 	 * 
	 	 * @param vec [Vector]
	 	 * @tparam U  [Generic type]
	 	 * @return    [Return the copy of parameter vector that was normalize]
	 	 */
		template<typename U>
		friend inline FF::Vector4<U>& Normalize(const FF::Vector4<U>& __FF_IN vec);



		/**
		 * @brief [Default destructor]
		 */
		~Vector4(void) = default;



		/**
		 * @brief [Debug override << operator]
		 * @details [Used for output values in ostream. Friend function]
		 * 
		 * @param out [Out stream]
		 * @param vec [Vector]
		 */
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
	inline void FF::Vector4<T>::SetXComponent(T __FF_IN x) noexcept {
		this->m_x = x;
	}

	template<typename T>
	inline void FF::Vector4<T>::SetYComponent(T __FF_IN y) noexcept {
		this->m_y = y;
	}

	template<typename T>
	inline void FF::Vector4<T>::SetZComponent(T __FF_IN z) noexcept {
		this->m_z = z;
	}

	template<typename T>
	inline void FF::Vector4<T>::SetWComponent(T __FF_IN w) noexcept {
		this->m_w = w;
	}

	template<typename T>
    inline void FF::Vector4<T>::SetXYZW(const T __FF_IN x, const T __FF_IN y, const T __FF_IN z, const T __FF_IN w) noexcept {
        this->m_x = x;
        this->m_y = y;
        this->m_z = z;
        this->m_w = w;
    }

	template<typename T>
	const inline T& FF::Vector4<T>::GetXComponent(void) const noexcept {
		return m_x;
	}

	template<typename T>
	const inline T& FF::Vector4<T>::GetYComponent(void) const noexcept {
		return m_y;
	}

	template<typename T>
	const inline T& FF::Vector4<T>::GetZComponent(void) const noexcept {
		return m_z;
	}

	template<typename T>
	const inline T& FF::Vector4<T>::GetWComponent(void) const noexcept {
		return m_w;
	}

	template<typename T>
	FF::Vector4<T> operator-(const FF::Vector4<T>& __FF_IN vec){
		return FF::Vector4<T>( -vec.m_x, 
			                   -vec.m_y, 
			                   -vec.m_z, 
			                   -vec.m_w);
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
		FF_ASSERT_MESSAGE(!FF::CloseToZero(scalar), "Scalar is 0x0 value. Divide by zero!");

		return FF::Vector4<T>( vec.m_x / scalar,
					 		   vec.m_y / scalar,
					 		   vec.m_z / scalar,
					 		   vec.m_w / scalar );
	}

	template<typename T>
	inline void FF::Vector4<T>::operator-=(const FF::Vector4<T>& __FF_IN vec) noexcept {
		this->m_x -= vec.m_x;
		this->m_y -= vec.m_y;
		this->m_z -= vec.m_z;
		this->m_w -= vec.m_w;
	}
		
	template<typename T>
	inline void FF::Vector4<T>::operator+=(const FF::Vector4<T>& __FF_IN vec) noexcept {
		this->m_x += vec.m_x;
		this->m_y += vec.m_y;
		this->m_z += vec.m_z;
		this->m_w += vec.m_w;
	}

	template<typename T>
	inline void FF::Vector4<T>::operator-=(const T& __FF_IN scalar) noexcept {
		this->m_x -= scalar;
		this->m_y -= scalar;
		this->m_z -= scalar;
		this->m_w -= scalar;
	}

	template<typename T>
	inline void FF::Vector4<T>::operator+=(const T& __FF_IN scalar) noexcept {
		this->m_x += scalar;
		this->m_y += scalar;
		this->m_z += scalar;
		this->m_w += scalar;
	}

	template<typename T>
	inline void FF::Vector4<T>::operator*=(const T& __FF_IN scalar) noexcept {
		this->m_x *= scalar;
		this->m_y *= scalar;
		this->m_y *= scalar;
		this->m_w *= scalar;
	}

	template<typename T>
	inline void FF::Vector4<T>::operator/=(const T& __FF_IN scalar){
		FF_ASSERT_MESSAGE(!FF::CloseToZero(scalar), "Scalar is 0x0 value. Divide by zero!");

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
	inline T FF::Vector4<T>::DotProduct(const FF::Vector4<T>& __FF_IN vec) const noexcept {
		return (this->m_x * vec.m_x + this->m_y * vec.m_y + this->m_z * vec.m_z + this->m_w * vec.m_w);
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
	inline T FF::Vector4<T>::Magnitude(void) const noexcept {	
		return sqrt( FF::sqr(this->m_x) + 
					 FF::sqr(this->m_y) + 
					 FF::sqr(this->m_z) + 
					 FF::sqr(this->m_w) );
	}

	template<typename T>
	inline T Magnitude(const FF::Vector4<T>& __FF_IN vec){	
		return sqrt( FF::sqr(vec.m_x) + 
					 FF::sqr(vec.m_y) + 
					 FF::sqr(vec.m_z) + 
					 FF::sqr(vec.m_w) );
	}

	template<typename T>
	inline T FF::Vector4<T>::SquaredMagnitude(void) const noexcept {
		return ( FF::sqr(this->m_x) + 
				 FF::sqr(this->m_y) + 
				 FF::sqr(this->m_z) +
				 FF::sqr(this->m_w) );
	}

	template<typename T>
	inline T SquaredMagnitude(const Vector4<T>& __FF_IN vec){
		return ( FF::sqr(vec.m_x) + 
				 FF::sqr(vec.m_y) + 
				 FF::sqr(vec.m_z) +
				 FF::sqr(vec.m_w) );
	}

	template<typename T>
	inline FF::Vector4<T> FF::Vector4<T>::Normalize(void) const {
		return ((*this) / this->Magnitude());
	}

	template<typename T>
	inline FF::Vector4<T> Normalize(const FF::Vector4<T>& __FF_IN vec){
		return (vec / FF::Magnitude(vec));
	}

	template<typename T>
	std::ostream& operator<< (std::ostream& __FF_IN out, Vector4<T>& __FF_IN vec){
		std::cout << "{" << vec.m_x << ", " << vec.m_y << "," << vec.m_z << "," << vec.m_w << "}" << std::endl;
		return out;
	}
};

#endif // FF_VECTOR4_HXX_