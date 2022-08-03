#include "FF_Macros.hxx"
#include "FF_Vector2.hxx"

#ifndef FF_MATRIX2X2_HXX_
#define FF_MATRIX2X2_HXX_

namespace FF {
	/**
	 * @brief [Class that represent two-dimensional matrix]
	 * 
	 * @tparam T [Generic type]
	 */
	template<typename T>
	class Matrix2x2 {
	private:
		T m_mat[0x2][0x2];
	public:
		/**
		 * @brief [Default constructor are not defined to all entities in FF]
		 * 
		 * @tparam T   [Generic type]
		 */
		explicit Matrix2x2(void) = delete;

		/**
		 * @brief [Constuctor with the parameters that have init MAT2 with scalar values]
		 * 
		 * @param v11 [Value with index (0,0)]
		 * @param v12 [Value with index (0,1)]
		 * @param v21 [Value with index (1,0)]
		 * @param v22 [Value with index (1,1)]
		 * @tparam T  [Generic type]
		 */
		explicit Matrix2x2(	const T __FF_IN v11 = static_cast<T>(0.0f), const T __FF_IN v12 = static_cast<T>(0.0f),
							const T __FF_IN v21 = static_cast<T>(0.0f), const T __FF_IN v22 = static_cast<T>(0.0f) )
		: m_mat{ v11, v12,
		 	 	 v21, v22 } {}

		/**
		 * @brief [Constuctor with the parameters that have init MAT2 with vectors]
		 * 
		 * @param vec1 [First vector]
		 * @param vec2 [Second vector]
		 * @tparam T   [Generic type]
		 */
		explicit Matrix2x2( FF::Vector2<T>& __FF_IN vec1,
							FF::Vector2<T>& __FF_IN vec2 );



		/**
		 * @brief   [Member function that set this matrix to identity matrix]
		 * @details [Set this matrix to identity matrix: [1 0],
		 * 			                                     [0 1] ]
		 * 	
		 * @tparam T [Generic type]
		 */
		inline void                     Identity(void) noexcept ;

		/**
		 * @brief   [Friend function that instance identity matrix]
		 * @details [Return identity matrix: [1 0],
		 * 			                         [0 1] ]
		 * 	
		 * @tparam U [Generic type]		  
		 * @return   [Return identity matrix]
		 * 
		 */
		template<typename U>
		friend inline FF::Matrix2x2<U>& Identity(void) noexcept ;



		/**
		 * @brief   [Operator that calculate difference of this matrix and scalar]
		 * @details [Matrix - scalar is each component of matrix minus scalar]
		 * 
		 * @param scalar [Scalar value]
		 * @tparam T     [Generic type]
		 */
		inline void operator-=(const T& __FF_IN scalar) noexcept;

		/**
		 * @brief   [Operator that calculate sum of this matrix and scalar]
		 * @details [Matrix + scalar is each component of matrix plus scalar]
		 * 
		 * @param scalar [Scalar value]
		 * @tparam T     [Generic type]
		 */
		inline void operator+=(const T& __FF_IN scalar) noexcept;

		/**
		 * @brief   [Operator that calculate mul of this matrix and scalar]
		 * @details [Matrix * scalar is each component of matrix mul scalar]
		 * 
		 * @param scalar [Scalar value]
		 * @tparam T     [Generic type]
		 */
		inline void operator*=(const T& __FF_IN scalar) noexcept;

		/**
		 * @brief   [Operator that calculate div of this matrix and scalar]
		 * @details [Matrix / scalar is each component of matrix div scalar]
		 * 
		 * @param scalar [Scalar value]
		 * @tparam T     [Generic type]
		 */
		inline void operator/=(const T& __FF_IN scalar);



		/**
		 * @brief   [Operator that calculate dif with this matrix and parameter matrix]
		 * @details [Matrix - matrix is matrix that each component that Aij - Bij, where A and B - matrices,
		 *           i and j - indexes]
		 * 
		 * @param vec [Matrix]
		 * @tparam T  [Generic type]
		 */
		inline void operator-=(const FF::Matrix2x2<T>& __FF_IN mat) noexcept;

		/**
		 * @brief   [Operator that calculate sum with this matrix and parameter matrix]
		 * @details [Matrix + matrix is matrix that each component that Aij + Bij, where A and B - matrices,
		 *           i and j - indexes]
		 * 
		 * @param vec [Matrix]
		 * @tparam T  [Generic type]
		 */
		inline void operator+=(const FF::Matrix2x2<T>& __FF_IN mat) noexcept;



		/**
		 * @brief   [Friend function that return -mat]
		 * @details [Apply '-' to each component]
		 * 
		 * @param mat [Matrix]
		 * @tparam U  [Generic type]
		 * @return    [Return matrix that represent origin matrix with other sign]
		 */
		template<typename U>
		friend inline FF::Matrix2x2<U> operator-(const FF::Matrix2x2<U>& __FF_IN mat);

		/**
		 * @brief   [Friend function that calculate difference of two mats]
		 * @details [Each component is difference of appropriate components of parameter matrix]
		 * 
		 * @param mat1 [First matrix]
		 * @param mat2 [Second matrix]
		 * @tparam U   [Generic type]
		 * @return     [Return matrix that represent difference of two matrix]
		 */
		template<typename U>
		friend inline FF::Matrix2x2<U> operator-(const FF::Matrix2x2<U>& __FF_IN mat1, const FF::Matrix2x2<U>& __FF_IN mat2);

		/**
		 * @brief   [Friend function that calculate sum of two mats]
		 * @details [Each component is sum of appropriate components of parameter matrix]
		 * 
		 * @param mat1 [First matrix]
		 * @param mat2 [Second matrix]
		 * @tparam U   [Generic type]
		 * @return     [Return matrix that represent sum of two matrix]
		 */
		template<typename U>
		friend inline FF::Matrix2x2<U> operator+(const FF::Matrix2x2<U>& __FF_IN mat1, const FF::Matrix2x2<U>& __FF_IN mat2);

		/**
		 * @brief   [Friend function that calculate mul of two mats]
		 * @details [Each component is mul of appropriate components of appropriate row and column]
		 * 
		 * @param mat1 [First matrix]
		 * @param mat2 [Second matrix]
		 * @tparam U   [Generic type]
		 * @return     [Return matrix that represent mul of two matrix]
		 */
		template<typename U>
		friend inline FF::Matrix2x2<U> operator*(const FF::Matrix2x2<U>& __FF_IN mat1, const FF::Matrix2x2<U>& __FF_IN mat2);

		/**
		 * @brief   [Friend function that calculate mul of vec and mat]
		 * @details [Each component is mul of appropriate components of appropriate row and column]
		 * 
		 * @param mat [Matrix]
		 * @param vec [Vector]
		 * @tparam U  [Generic type]
		 * @return    [Return vector that represent vec * mat]
		 */
		template<typename U>
		friend inline FF::Vector2<U>   operator*(const Matrix2x2& __FF_IN mat,  const FF::Vector2<U>& __FF_IN vec);

		

		/**
		 * @brief   [Friend function that calculate difference of mat and scalar]
		 * @details [Each component is difference of appropriate components of parameter matrix]
		 * 
		 * @param mat    [Matrix]
		 * @param scalar [Scalar value]
		 * @tparam U     [Generic type]
		 * @return       [Return matrix that mat - scalar]
		 */
		template<typename U>
		friend inline FF::Matrix2x2<U> operator-(const FF::Matrix2x2<U>& __FF_IN mat,  const U& __FF_IN scalar);

		/**
		 * @brief   [Friend function that calculate sum of matrix and scalar]
		 * @details [Each component is sum of appropriate components origin vectors]
		 * 
		 * @param vec [Vector]
		 * @tparam U  [Generic type]
		 * @return    [Return matrix that represent sum of origin vectors]
		 */
		template<typename U>
		friend inline FF::Matrix2x2<U> operator+(const FF::Matrix2x2<U>& __FF_IN mat,  const U& __FF_IN scalar);

		/**
		 * @brief   [Friend function that calculate composition mat and scalar value]
		 * @details [Each component mul to scalar]
		 * 
		 * @param mat [Vector]
		 * @tparam U  [Generic type]
		 * @return    [Return matrix that represent mul of origin matrix and scalar value]
		 */
		template<typename U>
		friend inline FF::Matrix2x2<U> operator*(const FF::Matrix2x2<U>& __FF_IN mat,  const U& __FF_IN scalar);

		/**
		 * @brief   [Friend function that calculate division matrix and scalar value]
		 * @details [Each component divide to scalar]
		 * 
		 * @param mat [Matrix]
		 * @tparam U  [Generic type]
		 * @return    [Return vector that represent div of origin matrix and scalar value]
		 */
		template<typename U>
		friend inline FF::Matrix2x2<U> operator/(const FF::Matrix2x2<U>& __FF_IN mat,  const U& __FF_IN scalar);

		

		/**
		 * @brief [Method that calculate determinant of matrix]
		 * 
		 * @tparam T [Generic type]
		 * 
		 * @return   [Return determinant]
		 */
		inline T&& 	      Determinant(void) const noexcept;

		/**
		 * @brief [Friend function that calculate determinant of matrix]
		 * 
		 * @tparam T [Generic type]
		 * 
		 * @return   [Return determinant]
		 */
		template<typename U>
		friend inline U&& Determinant(const FF::Matrix2x2<U>& __FF_IN mat);



		/**
		 * @brief [Method that return row of matrix such a vector]
		 * 
		 * @param index [Index of row]
		 * @tparam T    [Generic type]
		 * 
		 * 
		 * @return      [Return vector]
		 */
		inline FF::Vector2<T> operator[](const std::size_t& __FF_IN rowNumber);

		/**
		 * @brief [Method that get ij element of matrix]
		 * 
		 * @param j  [Row index]
		 * @param i  [Column index]
		 * @tparam T [Generic type]
		 * 
		 * @return   [Return element as lvalue]
		 */
		inline T&             operator()(const std::size_t& __FF_IN i, const std::size_t& __FF_IN i);



		/**
		 * @brief   [Debug override << operator]
		 * @details [Used for output values in ostream. Friend function]
		 * 
		 * @param out [Out stream]
		 * @param m   [Matrix]
		 */
		template<typename U>
		friend inline std::ostream& operator<<(std::ostream& out, const FF::Matrix2x2<U>& m);



		/**
		 * @brief [Default destructor]
		 * 
		 * @tparam T [Generic type]
		 */
		~Matrix2x2(void) = default;
	};	

	template<typename T>
	FF::Matrix2x2<T>::Matrix2x2( FF::Vector2<T>& __FF_IN vec1,
					      		 FF::Vector2<T>& __FF_IN vec2 )
	: m_mat{ vec1.getXComponent(vec1), vec1.getYComponent(vec1),
		 	 vec2.getXComponent(vec2), vec2.getYComponent(vec2) } {}

	template<typename T>
	inline void FF::Matrix2x2<T>::Identity(void) noexcept {
		this->m_mat[0x0][0x0] = 1.0f; this->m_mat[0x0][0x1] = 0.0f;
		this->m_mat[0x1][0x0] = 0.0f; this->m_mat[0x1][0x1] = 1.0f;
	}

	template<typename T>
	inline FF::Matrix2x2<T>& Identity(void) noexcept {
		return FF::Matrix2x2<T>( static_cast<T>(1.0f), static_cast<T>(0.0f),
				  	 			 static_cast<T>(0.0f), static_cast<T>(1.0f) );
	}

	template<typename T>
	inline void FF::Matrix2x2<T>::operator-=(const T& __FF_IN scalar) noexcept {
		this->m_mat[0x0][0x0] -= scalar; this->m_mat[0x0][0x1] -= scalar;
		this->m_mat[0x1][0x0] -= scalar; this->m_mat[0x1][0x1] -= scalar;
	}

	template<typename T>
	inline void FF::Matrix2x2<T>::operator+=(const T& __FF_IN scalar) noexcept {
		this->m_mat[0x0][0x0] += scalar; this->m_mat[0x0][0x1] += scalar;
		this->m_mat[0x1][0x0] += scalar; this->m_mat[0x1][0x1] += scalar;
	}

	template<typename T>
	inline void FF::Matrix2x2<T>::operator*=(const T& __FF_IN scalar) noexcept {
		this->m_mat[0x0][0x0] *= scalar; this->m_mat[0x0][0x1] *= scalar; 
		this->m_mat[0x1][0x0] *= scalar; this->m_mat[0x1][0x1] *= scalar; 
	}

	template<typename T>
	inline void FF::Matrix2x2<T>::operator/=(const T& __FF_IN scalar){
		FF_ASSERT_MESSAGE(!FF::CloseToZero(scalar), "Scalar is 0x0 value. Divide by zero!");

		T divCoeff = 0x1 / scalar;
		this->m_mat[0x0][0x0] *= divCoeff; this->m_mat[0x0][0x1] *= divCoeff;
		this->m_mat[0x1][0x0] *= divCoeff; this->m_mat[0x1][0x1] *= divCoeff;
	}

	template<typename T>
	inline void FF::Matrix2x2<T>::operator-=(const FF::Matrix2x2<T>& __FF_IN mat) noexcept {
		this->m_mat[0x0][0x0] -= mat.m_mat[0x0][0x0]; this->m_mat[0x0][0x1] -= mat.m_mat[0x0][0x1];
		this->m_mat[0x1][0x0] -= mat.m_mat[0x1][0x0]; this->m_mat[0x1][0x1] -= mat.m_mat[0x1][0x1];
	}

	template<typename T>
	inline void FF::Matrix2x2<T>::operator+=(const FF::Matrix2x2<T>& __FF_IN mat) noexcept {
		this->m_mat[0x0][0x0] += mat.m_mat[0x0][0x0]; this->m_mat[0x0][0x1] += mat.m_mat[0x0][0x1];
		this->m_mat[0x1][0x0] += mat.m_mat[0x1][0x0]; this->m_mat[0x1][0x1] += mat.m_mat[0x1][0x1];
	}

	

	template<typename T>
	inline FF::Matrix2x2<T> operator-(const FF::Matrix2x2<T>& __FF_IN mat){
		return FF::Matrix2x2<T>( -mat.m_mat[0x0][0x0], -mat.m_mat[0x0][0x1],
				  	             -mat.m_mat[0x1][0x0], -mat.m_mat[0x1][0x1] );
	}

	template<typename T>
	inline FF::Matrix2x2<T> operator-(const FF::Matrix2x2<T>& __FF_IN mat1, const FF::Matrix2x2<T>& __FF_IN mat2){
		return FF::Matrix2x2<T>( mat1.m_mat[0x0][0x0] - mat2.m_mat[0x0][0x0], mat1.m_mat[0x0][0x1] - mat2.m_mat[0x0][0x1],
				  	             mat1.m_mat[0x1][0x0] - mat2.m_mat[0x1][0x0], mat1.m_mat[0x1][0x1] - mat2.m_mat[0x1][0x1] );
	}

	template<typename T>
	inline FF::Matrix2x2<T> operator+(const FF::Matrix2x2<T>& __FF_IN mat1, const FF::Matrix2x2<T>& __FF_IN mat2){
		return FF::Matrix2x2<T>( mat1.m_mat[0x0][0x0] + mat2.m_mat[0x0][0x0], mat1.m_mat[0x0][0x1] + mat2.m_mat[0x0][0x1],
				  	             mat1.m_mat[0x1][0x0] + mat2.m_mat[0x1][0x0], mat1.m_mat[0x1][0x1] + mat2.m_mat[0x1][0x1] );
	}

	template<typename T>
	inline FF::Matrix2x2<T> operator*(const FF::Matrix2x2<T>& __FF_IN mat1, const FF::Matrix2x2<T>& __FF_IN mat2){
		return FF::Matrix2x2<T>( mat1.m_mat[0x0][0x0] * mat2.m_mat[0x0][0x0] + mat1.m_mat[0x0][0x1] * mat2.m_mat[0x1][0x0],
				  	             mat1.m_mat[0x0][0x0] * mat2.m_mat[0x0][0x1] + mat1.m_mat[0x0][0x1] * mat2.m_mat[0x1][0x1],

				  	             mat1.m_mat[0x1][0x0] * mat2.m_mat[0x0][0x0] + mat1.m_mat[0x1][0x1] * mat2.m_mat[0x1][0x0],
				  	             mat1.m_mat[0x1][0x0] * mat2.m_mat[0x0][0x1] + mat1.m_mat[0x1][0x1] * mat2.m_mat[0x1][0x1] );
	}

	template<typename T>
	inline FF::Vector2<T>   operator*(const FF::Matrix2x2<T>& __FF_IN mat,  const FF::Vector2<T>& __FF_IN vec){
		return FF::Vector2<T>( mat.m_mat[0x0][0x0] * vec.getXComponent(vec) + mat.m_mat[0x0][0x1] * vec.getYComponent(vec),
				  	           mat.m_mat[0x1][0x0] * vec.getXComponent(vec) + mat.m_mat[0x1][0x1] * vec.getYComponent(vec) );
	}

	template<typename T>
	inline FF::Matrix2x2<T> operator-(const FF::Matrix2x2<T>& __FF_IN mat,  const T& __FF_IN scalar){
		return FF::Matrix2x2<T>( mat.m_mat[0x0][0x0] - scalar, mat.m_mat[0x0][0x1] - scalar,
				  		         mat.m_mat[0x1][0x0] - scalar, mat.m_mat[0x1][0x1] - scalar );
	}

	template<typename T>
	inline FF::Matrix2x2<T> operator+(const FF::Matrix2x2<T>& __FF_IN mat,  const T& __FF_IN scalar){
		return FF::Matrix2x2<T>( mat.m_mat[0x0][0x0] + scalar, mat.m_mat[0x0][0x1] + scalar,
				  	             mat.m_mat[0x1][0x0] + scalar, mat.m_mat[0x1][0x1] + scalar );
	}

	template<typename T>
	inline FF::Matrix2x2<T> operator*(const FF::Matrix2x2<T>& __FF_IN mat,  const T& __FF_IN scalar){
		return FF::Matrix2x2<T>( mat.m_mat[0x0][0x0] * scalar, mat.m_mat[0x0][0x1] * scalar,
				  	             mat.m_mat[0x1][0x0] * scalar, mat.m_mat[0x1][0x1] * scalar );
	}

	template<typename T>
	inline FF::Matrix2x2<T> operator/(const FF::Matrix2x2<T>& __FF_IN mat,  const T& __FF_IN scalar){
		FF_ASSERT_MESSAGE(!FF::CloseToZero(scalar), "Scalar is 0x0 value. Divide by zero!");

		T divCoeff = 0x1 / scalar;
		return FF::Matrix2x2<T>( mat.m_mat[0x0][0x0] * divCoeff, mat.m_mat[0x0][0x1] * divCoeff,
				  	             mat.m_mat[0x1][0x0] * divCoeff, mat.m_mat[0x1][0x1] * divCoeff );
	}

	template<typename T>
	inline T&& FF::Matrix2x2<T>::Determinant(void) const noexcept {
		return ( this->m_mat[0x0][0x0] * this->m_mat[0x1][0x1] - this->m_mat[0x0][0x1] * this->m_mat[0x1][0x0] );
	}

	template<typename T>
	inline T&& Determinant(const FF::Matrix2x2<T>& __FF_IN mat){
		return ( mat.m_mat[0x0][0x0] * mat.m_mat[0x1][0x1] - mat.m_mat[0x0][0x1] * mat.m_mat[0x1][0x0] );
	}

	template<typename T>
	inline FF::Vector2<T> FF::Matrix2x2<T>::operator[](const std::size_t& __FF_IN rowNumber){
		FF_STATIC_ASSERT_MESSAGE(rowNumber < 0x2uL, "Going beyond the vector!");

		return FF::Vector2<T>(m_mat[rowNumber][0x0], m_mat[rowNumber][0x1]);
	}

	template<typename T>
	inline T& operator()(const std::size_t& __FF_IN i, const std::size_t& __FF_IN i){
		FF_STATIC_ASSERT_MESSAGE(i < 0x2uL && j < 0x2uL, "I or J index greater 0x2. Going beyond array bound!");

		return this->m_mat[i][j];
	}

	template<typename T>
	inline std::ostream& operator<<(std::ostream& out, const FF::Matrix2x2<T>& m){
		std::cout << m.m_mat[0x0][0x0] << " | " << m.m_mat[0x0][0x1] << std::endl;
		std::cout << m.m_mat[0x1][0x0] << " | " << m.m_mat[0x1][0x1] << std::endl;

		return out;
	}
};

#endif // FF_MATRIX2X2_HXX_