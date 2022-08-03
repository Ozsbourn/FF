#include "FF_Macros.hxx"
#include "FF_Vector3.hxx"

#ifndef FF_MATRIX3X3_HXX_
#define FF_MATRIX3X3_HXX_

namespace FF {
	/**
	 * @brief [Class that represent three-dimensional matrix]
	 * 
	 * @tparam T [Generic type]
	 */
	template<typename T>
	class Matrix3x3 {
	private:
		T m_mat[0x3][0x3];
	public:
		/**
		 * @brief [Default constructor are not defined to all entities in FF]
		 * 
		 * @tparam T [Generic type]
		 */
		explicit Matrix3x3(void) = delete;

		/**
		 * @brief [Constuctor with the parameters that have init MAT3 with scalar values]
		 * 
		 * @param v11 [Value with index (0,0)]
		 * @param v12 [Value with index (0,1)]
		 * @param v13 [Value with index (0,2)]
		 * @param v21 [Value with index (1,0)]
		 * @param v22 [Value with index (1,1)]
		 * @param v23 [Value with index (1,2)]
		 * @param v31 [Value with index (2,0)]
		 * @param v32 [Value with index (2,1)]
		 * @param v33 [Value with index (2,2)]
		 * 
		 * @tparam T  [Generic type]
		 */
		explicit Matrix3x3(	const T __FF_IN v11 = static_cast<T>(0.0f), const T __FF_IN v12 = static_cast<T>(0.0f), const T __FF_IN v13 = static_cast<T>(0.0f),
							const T __FF_IN v21 = static_cast<T>(0.0f), const T __FF_IN v22 = static_cast<T>(0.0f), const T __FF_IN v23 = static_cast<T>(0.0f),
							const T __FF_IN v31 = static_cast<T>(0.0f), const T __FF_IN v32 = static_cast<T>(0.0f), const T __FF_IN v33 = static_cast<T>(0.0f) )
		: m_mat{ v11, v12, v13,
		 		 v21, v22, v23,
		 		 v31, v32, v33 } {}

		/**
		 * @brief [Constuctor with the parameters that have init MAT3 with vectors]
		 * 
		 * @param vec1 [First vector]
		 * @param vec2 [Second vector]
		 * @param vec3 [Third vector]
		 * 
		 * @tparam T   [Generic type]
		 */
		explicit Matrix3x3( FF::Vector3<T>& __FF_IN vec1,
							FF::Vector3<T>& __FF_IN vec2,
							FF::Vector3<T>& __FF_IN vec3 );



		/**
		 * @brief   [Member function that instance identity matrix]
		 * @details [Set this matrix to identity: [1 0 0],
		 * 			                              [0 1 0],
		 * 			                              [0 0 1] ]
		 * 			                              
		 * @tparam T [Generic type]
		 */
		inline void                     Identity(void) noexcept;

		/**
		 * @brief   [Friend function that instance identity matrix]
		 * @details [Return the identity matrix: [1 0 0],
		 * 			                             [0 1 0],
		 * 			                             [0 0 1] ]
		 * @return [Return identity matrix]
		 */
		template<typename U>
		friend inline FF::Matrix3x3<U>& Identity(void);



		/**
		 * @brief   [Operator that calculate difference of this matrix and scalar]
		 * @details [Matrix - scalar is each component of matrix minus scalar]
		 * 
		 * @param scalar [Scalar value]
		 * @tparam T  [Generic type]
		 */
		inline void operator-=(const T& __FF_IN scalar) noexcept;

		/**
		 * @brief   [Operator that calculate sum of this matrix and scalar]
		 * @details [Matrix + scalar is each component of matrix plus scalar]
		 * 
		 * @param scalar [Scalar value]
		 * @tparam T  [Generic type]
		 */
		inline void operator+=(const T& __FF_IN scalar) noexcept;

		/**
		 * @brief   [Operator that calculate mul of this matrix and scalar]
		 * @details [Matrix * scalar is each component of matrix mul scalar]
		 * 
		 * @param scalar [Scalar value]
		 * @tparam T  [Generic type]
		 */
		inline void operator*=(const T& __FF_IN scalar) noexcept;

		/**
		 * @brief   [Operator that calculate div of this matrix and scalar]
		 * @details [Matrix / scalar is each component of matrix div scalar]
		 * 
		 * @param scalar [Scalar value]
		 * @tparam T  [Generic type]
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
		inline void operator-=(const FF::Matrix3x3<T>& __FF_IN mat) noexcept;

		/**
		 * @brief   [Operator that calculate sum with this matrix and parameter matrix]
		 * @details [Matrix + matrix is matrix that each component that Aij + Bij, where A and B - matrices,
		 *           i and j - indexes]
		 * 
		 * @param vec [Matrix]
		 * @tparam T  [Generic type]
		 */
		inline void operator+=(const FF::Matrix3x3<T>& __FF_IN mat) noexcept;



		/**
		 * @brief   [Friend function that return -mat]
		 * @details [Apply '-' to each component]
		 * 
		 * @param mat [Matrix]
		 * @tparam U  [Generic type]
		 * @return    [Return matrix that represent origin matrix with other sign]
		 */
		template<typename U>
		friend inline FF::Matrix3x3<U> operator-(const FF::Matrix3x3<U>& __FF_IN mat);

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
		friend inline FF::Matrix3x3<U> operator-(const FF::Matrix3x3<U>& __FF_IN mat1, const FF::Matrix3x3<U>& __FF_IN mat2);

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
		friend inline FF::Matrix3x3<U> operator+(const FF::Matrix3x3<U>& __FF_IN mat1, const FF::Matrix3x3<U>& __FF_IN mat2);

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
		friend inline FF::Matrix3x3<U> operator*(const FF::Matrix3x3<U>& __FF_IN mat1, const FF::Matrix3x3<U>& __FF_IN mat2);



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
		friend inline FF::Vector3<U>   operator*(const FF::Matrix3x3<U>& __FF_IN mat,  const FF::Vector3<U>& __FF_IN vec);



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
		friend inline FF::Matrix3x3<U> operator-(const FF::Matrix3x3<U>& __FF_IN mat,  const U& __FF_IN scalar);

		/**
		 * @brief   [Friend function that calculate sum of matrix and scalar]
		 * @details [Each component is sum of appropriate components origin vectors]
		 * 
		 * @param mat    [Matrix]
		 * @param scalar [Scalar value]
		 * @tparam U     [Generic type]
		 * @return       [Return matrix that represent sum of origin vectors]
		 */
		template<typename U>
		friend inline FF::Matrix3x3<U> operator+(const FF::Matrix3x3<U>& __FF_IN mat,  const U& __FF_IN scalar);

		/**
		 * @brief   [Friend function that calculate composition mat and scalar value]
		 * @details [Each component mul to scalar]
		 * 
		 * @param mat    [Matrix]
		 * @param scalar [Scalar value]
		 * @tparam U     [Generic type]
		 * @return       [Return matrix that represent mul of origin matrix and scalar value]
		 */
		template<typename U>
		friend inline FF::Matrix3x3<U> operator*(const FF::Matrix3x3<U>& __FF_IN mat,  const U& __FF_IN scalar);

		/**
		 * @brief   [Friend function that calculate division matrix and scalar value]
		 * @details [Each component divide to scalar]
		 * 
		 * @param mat    [Matrix]
		 * @param scalar [Scalar value]
		 * @tparam U     [Generic type]
		 * @return       [Return vector that represent div of origin matrix and scalar value]
		 */
		template<typename U>
		friend inline FF::Matrix3x3<U> operator/(const FF::Matrix3x3<U>& __FF_IN mat,  const U& __FF_IN scalar);


		
		/**
		 * @brief [Method that calculate determinant of matrix]
		 * 
		 * @tparam T [Generic type]
		 * @return   [Return determinant]
		 */
		inline T&& 	      Determinant(void) const noexcept;

		/**
		 * @brief [Friend function that calculate determinant of matrix]
		 * 
		 * @tparam U [Generic type]
		 * @return   [Return determinant]
		 */
		template<typename U>
		friend inline U&& Determinant(const FF::Matrix3x3<U>& __FF_IN mat);



		/**
		 * @brief   [Method that return row of matrix such a vector]
		 * @details [Return vector in ROW_NUMBER position]
		 * 
		 * @param rowNumber [Index of row]
		 * @tparam T        [Generic type]
		 * @return          [Return vector]
		 */
		inline FF::Vector3<T>  operator[](const std::size_t& __FF_IN rowNumber);

		/**
		 * @brief   [Method that return element by indexes]
		 * @details [Return element in ij position in matrix as lvalue]
		 * 
		 * @param i  [Index of row]
		 * @param j  [Index of column]
		 * @tparam T [Generic type]
		 * @return   [Return element]
		 */
		inline const T&        operator()(const std::size_t& __FF_IN i, const std::size_t& __FF_IN j);

		

        /**
		 * @brief [Default destructor]
		 */
		~Matrix3x3(void) = default;



		/**
		 * @brief   [Debug override << operator]
		 * @details [Used for output values in ostream. Friend function]
		 * 
		 * @param out [Out stream]
		 * @param m   [Matrix]
		 * @tparam T  [Generic type]
		 */
		template<typename U>
		friend inline std::ostream& operator<<(std::ostream& __FF_OUT out, const FF::Matrix3x3<U>& __FF_IN m);		
	};

	template<typename T>
	FF::Matrix3x3<T>::Matrix3x3( FF::Vector3<T>& __FF_IN vec1,
						 	     FF::Vector3<T>& __FF_IN vec2,
						 	     FF::Vector3<T>& __FF_IN vec3 )
	: m_mat{ vec1.getXComponent(), vec1.getYComponent(), vec1.GetZComponent(),
		 	 vec2.getXComponent(), vec2.getYComponent(), vec2.GetZComponent(),
		 	 vec3.getXComponent(), vec3.getYComponent(), vec3.GetZComponent() } {}

    template<typename T>
	inline void FF::Matrix3x3<T>::Identity(void) noexcept {
		this->m_mat[0x0][0x0] = 1.0f; this->m_mat[0x0][0x1] = 0.0f; this->m_mat[0x0][0x2] = 0.0f;
		this->m_mat[0x1][0x0] = 0.0f; this->m_mat[0x1][0x1] = 1.0f; this->m_mat[0x1][0x2] = 0.0f;
		this->m_mat[0x2][0x0] = 0.0f; this->m_mat[0x2][0x1] = 1.0f; this->m_mat[0x2][0x2] = 0.0f;
	}

	template<typename T>
	inline FF::Matrix3x3<T>& Identity(void){
		return FF::Matrix3x3<T>( static_cast<T>(1.0f), static_cast<T>(0.0f), static_cast<T>(0.0f),
				  		  	     static_cast<T>(0.0f), static_cast<T>(1.0f), static_cast<T>(0.0f),
				  		   		 static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(1.0f) );
	}

	template<typename T>
	inline void FF::Matrix3x3<T>::operator-=(const T& __FF_IN scalar) noexcept {
		this->m_mat[0x0][0x0] -= scalar; this->m_mat[0x0][0x1] -= scalar; this->m_mat[0x0][0x2] -= scalar;
		this->m_mat[0x1][0x0] -= scalar; this->m_mat[0x1][0x1] -= scalar; this->m_mat[0x1][0x2] -= scalar;
		this->m_mat[0x2][0x0] -= scalar; this->m_mat[0x2][0x1] -= scalar; this->m_mat[0x2][0x2] -= scalar;
	}

	template<typename T>
	inline void FF::Matrix3x3<T>::operator+=(const T& __FF_IN scalar) noexcept {
		this->m_mat[0x0][0x0] += scalar; this->m_mat[0x0][0x1] += scalar; this->m_mat[0x0][0x2] += scalar;
		this->m_mat[0x1][0x0] += scalar; this->m_mat[0x1][0x1] += scalar; this->m_mat[0x1][0x2] += scalar;
		this->m_mat[0x2][0x0] += scalar; this->m_mat[0x2][0x1] += scalar; this->m_mat[0x2][0x2] += scalar;
	}

	template<typename T>
	inline void FF::Matrix3x3<T>::operator*=(const T& __FF_IN scalar) noexcept {
		this->m_mat[0x0][0x0] *= scalar; this->m_mat[0x0][0x1] *= scalar; this->m_mat[0x0][0x2] *= scalar;
		this->m_mat[0x1][0x0] *= scalar; this->m_mat[0x1][0x1] *= scalar; this->m_mat[0x1][0x2] *= scalar;
		this->m_mat[0x2][0x0] *= scalar; this->m_mat[0x2][0x1] *= scalar; this->m_mat[0x2][0x2] *= scalar;
	}

	template<typename T>
	inline void FF::Matrix3x3<T>::operator/=(const T& __FF_IN scalar){
		FF_ASSERT_MESSAGE(!FF::CloseToZero(scalar), "Scalar is 0x0 value. Divide by zero!");

		T divCoeff = 0x1 / scalar;
		this->m_mat[0x0][0x0] *= divCoeff; this->m_mat[0x0][0x1] *= divCoeff; this->m_mat[0x0][0x2] *= divCoeff;
		this->m_mat[0x1][0x0] *= divCoeff; this->m_mat[0x1][0x1] *= divCoeff; this->m_mat[0x1][0x2] *= divCoeff;
		this->m_mat[0x2][0x0] *= divCoeff; this->m_mat[0x2][0x1] *= divCoeff; this->m_mat[0x2][0x2] *= divCoeff;
	}

	template<typename T>
	inline void FF::Matrix3x3<T>::operator-=(const FF::Matrix3x3<T>& __FF_IN mat) noexcept {
		this->m_mat[0x0][0x0] -= mat.m_mat[0x0][0x0]; this->m_mat[0x0][0x1] -= mat.m_mat[0x0][0x1]; this->m_mat[0x0][0x2] -= mat.m_mat[0x0][0x2];
		this->m_mat[0x1][0x0] -= mat.m_mat[0x1][0x0]; this->m_mat[0x1][0x1] -= mat.m_mat[0x1][0x1]; this->m_mat[0x1][0x2] -= mat.m_mat[0x1][0x2];
		this->m_mat[0x2][0x0] -= mat.m_mat[0x2][0x0]; this->m_mat[0x2][0x1] -= mat.m_mat[0x2][0x1]; this->m_mat[0x2][0x2] -= mat.m_mat[0x2][0x2];
	}

	template<typename T>
	inline void FF::Matrix3x3<T>::operator+=(const FF::Matrix3x3<T>& __FF_IN mat) noexcept {
		this->m_mat[0x0][0x0] += mat.m_mat[0x0][0x0]; this->m_mat[0x0][0x1] += mat.m_mat[0x0][0x1]; this->m_mat[0x0][0x2] += mat.m_mat[0x0][0x2];
		this->m_mat[0x1][0x0] += mat.m_mat[0x1][0x0]; this->m_mat[0x1][0x1] += mat.m_mat[0x1][0x1]; this->m_mat[0x1][0x2] += mat.m_mat[0x1][0x2];
		this->m_mat[0x2][0x0] += mat.m_mat[0x2][0x0]; this->m_mat[0x2][0x1] += mat.m_mat[0x2][0x1]; this->m_mat[0x2][0x2] += mat.m_mat[0x2][0x2];
	}

	template<typename T>
	inline FF::Matrix3x3<T> operator-(const FF::Matrix3x3<T>& __FF_IN mat){
		return FF::Matrix3x3<T>( -mat.m_mat[0x0][0x0], -mat.m_mat[0x0][0x1], -mat.m_mat[0x0][0x2],
				  		   		 -mat.m_mat[0x1][0x0], -mat.m_mat[0x1][0x1], -mat.m_mat[0x1][0x2], 
				  		   		 -mat.m_mat[0x2][0x0], -mat.m_mat[0x2][0x1], -mat.m_mat[0x2][0x2] );
	}

	template<typename T>
	inline FF::Matrix3x3<T> operator-(const FF::Matrix3x3<T>& __FF_IN mat1, const FF::Matrix3x3<T>& __FF_IN mat2){
		return FF::Matrix3x3<T>( mat1.m_mat[0x0][0x0] - mat2.m_mat[0x0][0x0], mat1.m_mat[0x0][0x1] - mat2.m_mat[0x0][0x1], mat1.m_mat[0x0][0x2] - mat2.m_mat[0x0][0x2],
				  		   		 mat1.m_mat[0x1][0x0] - mat2.m_mat[0x1][0x0], mat1.m_mat[0x1][0x1] - mat2.m_mat[0x1][0x1], mat1.m_mat[0x1][0x2] - mat2.m_mat[0x1][0x2],
				  		   		 mat1.m_mat[0x2][0x0] - mat2.m_mat[0x2][0x0], mat1.m_mat[0x2][0x1] - mat2.m_mat[0x2][0x1], mat1.m_mat[0x2][0x2] - mat2.m_mat[0x2][0x2] );
	}

	template<typename T>
	inline FF::Matrix3x3<T> operator+(const FF::Matrix3x3<T>& __FF_IN mat1, const FF::Matrix3x3<T>& __FF_IN mat2){
		return FF::Matrix3x3<T>( mat1.m_mat[0x0][0x0] + mat2.m_mat[0x0][0x0], mat1.m_mat[0x0][0x1] + mat2.m_mat[0x0][0x1], mat1.m_mat[0x0][0x2] + mat2.m_mat[0x0][0x2],
				  		   		 mat1.m_mat[0x1][0x0] + mat2.m_mat[0x1][0x0], mat1.m_mat[0x1][0x1] + mat2.m_mat[0x1][0x1], mat1.m_mat[0x1][0x2] + mat2.m_mat[0x1][0x2],
				  		   		 mat1.m_mat[0x2][0x0] + mat2.m_mat[0x2][0x0], mat1.m_mat[0x2][0x1] + mat2.m_mat[0x2][0x1], mat1.m_mat[0x2][0x2] + mat2.m_mat[0x2][0x2] );
	}

	template<typename T>
	inline FF::Matrix3x3<T> operator*(const FF::Matrix3x3<T>& __FF_IN mat1, const FF::Matrix3x3<T>& __FF_IN mat2){
		return FF::Matrix3x3<T>( mat1.m_mat[0x0][0x0] * mat2.m_mat[0x0][0x0] + mat1.m_mat[0x0][0x1] * mat2.m_mat[0x1][0x0] + mat1.m_mat[0x0][0x2] * mat2.m_mat[0x2][0x0],
						  		 mat1.m_mat[0x0][0x0] * mat2.m_mat[0x0][0x1] + mat1.m_mat[0x0][0x1] * mat2.m_mat[0x1][0x1] + mat1.m_mat[0x0][0x2] * mat2.m_mat[0x2][0x1],
						  		 mat1.m_mat[0x0][0x0] * mat2.m_mat[0x0][0x2] + mat1.m_mat[0x0][0x1] * mat2.m_mat[0x1][0x2] + mat1.m_mat[0x0][0x2] * mat2.m_mat[0x2][0x2],

						  		 mat1.m_mat[0x1][0x0] * mat2.m_mat[0x0][0x0] + mat1.m_mat[0x1][0x1] * mat2.m_mat[0x1][0x0] + mat1.m_mat[0x1][0x2] * mat2.m_mat[0x2][0x0],
						  		 mat1.m_mat[0x1][0x0] * mat2.m_mat[0x0][0x1] + mat1.m_mat[0x1][0x1] * mat2.m_mat[0x1][0x1] + mat1.m_mat[0x1][0x2] * mat2.m_mat[0x2][0x1],
						  		 mat1.m_mat[0x1][0x0] * mat2.m_mat[0x0][0x2] + mat1.m_mat[0x1][0x1] * mat2.m_mat[0x1][0x2] + mat1.m_mat[0x1][0x2] * mat2.m_mat[0x2][0x2],

						  		 mat1.m_mat[0x2][0x0] * mat2.m_mat[0x0][0x0] + mat1.m_mat[0x2][0x1] * mat2.m_mat[0x1][0x0] + mat1.m_mat[0x2][0x2] * mat2.m_mat[0x2][0x0],
						  		 mat1.m_mat[0x2][0x0] * mat2.m_mat[0x0][0x1] + mat1.m_mat[0x2][0x1] * mat2.m_mat[0x1][0x1] + mat1.m_mat[0x2][0x2] * mat2.m_mat[0x2][0x1],
						  		 mat1.m_mat[0x2][0x0] * mat2.m_mat[0x0][0x2] + mat1.m_mat[0x2][0x1] * mat2.m_mat[0x1][0x2] + mat1.m_mat[0x2][0x2] * mat2.m_mat[0x2][0x2] );
	}

	template<typename T>
	inline FF::Vector3<T>   operator*(const FF::Matrix3x3<T>& __FF_IN mat,  const FF::Vector3<T>& __FF_IN vec){
		return FF::Vector3<T>( mat.m_mat[0x0][0x0] * getXComponent(vec) + mat.m_mat[0x0][0x1] * getYComponent(vec) + mat.m_mat[0x0][0x2] * getZComponent(vec),
						  	   mat.m_mat[0x1][0x0] * getXComponent(vec) + mat.m_mat[0x1][0x1] * getYComponent(vec) + mat.m_mat[0x1][0x2] * getZComponent(vec),
						  	   mat.m_mat[0x2][0x0] * getXComponent(vec) + mat.m_mat[0x2][0x1] * getYComponent(vec) + mat.m_mat[0x2][0x2] * getZComponent(vec) );
	}

	template<typename T>
	inline FF::Matrix3x3<T> operator-(const FF::Matrix3x3<T>& __FF_IN mat,  const T& __FF_IN scalar){
		return FF::Matrix3x3<T>( mat.m_mat[0x0][0x0] - scalar, mat.m_mat[0x0][0x1] - scalar, mat.m_mat[0x0][0x2] - scalar,
				  		   		 mat.m_mat[0x1][0x0] - scalar, mat.m_mat[0x1][0x1] - scalar, mat.m_mat[0x1][0x2] - scalar,
				  		   		 mat.m_mat[0x2][0x0] - scalar, mat.m_mat[0x2][0x1] - scalar, mat.m_mat[0x2][0x2] - scalar );
	}

	template<typename T>
	inline FF::Matrix3x3<T> operator+(const FF::Matrix3x3<T>& __FF_IN mat,  const T& __FF_IN scalar){
		return FF::Matrix3x3<T>( mat.m_mat[0x0][0x0] + scalar, mat.m_mat[0x0][0x1] + scalar, mat.m_mat[0x0][0x2] + scalar,
				  		   		 mat.m_mat[0x1][0x0] + scalar, mat.m_mat[0x1][0x1] + scalar, mat.m_mat[0x1][0x2] + scalar,
				  		   		 mat.m_mat[0x2][0x0] + scalar, mat.m_mat[0x2][0x1] + scalar, mat.m_mat[0x2][0x2] + scalar );
	}

	template<typename T>
	inline FF::Matrix3x3<T> operator*(const FF::Matrix3x3<T>& __FF_IN mat,  const T& __FF_IN scalar){
		return FF::Matrix3x3<T>( mat.m_mat[0x0][0x0] * scalar, mat.m_mat[0x0][0x1] * scalar, mat.m_mat[0x0][0x2] * scalar,
				  		   		 mat.m_mat[0x1][0x0] * scalar, mat.m_mat[0x1][0x1] * scalar, mat.m_mat[0x1][0x2] * scalar,
				  		   		 mat.m_mat[0x2][0x0] * scalar, mat.m_mat[0x2][0x1] * scalar, mat.m_mat[0x2][0x2] * scalar );
	}

	template<typename T>
	inline FF::Matrix3x3<T> operator/(const FF::Matrix3x3<T>& __FF_IN mat,  const T& __FF_IN scalar){
        FF_ASSERT_MESSAGE(!FF::CloseToZero(scalar), "Scalar is 0x0 value. Divide by zero!");

		T divCoeff = 0x1 / scalar;
		return FF::Matrix3x3<T>( mat.m_mat[0x0][0x0] * divCoeff, mat.m_mat[0x0][0x1] * divCoeff, mat.m_mat[0x0][0x2] * divCoeff,
				  		   		 mat.m_mat[0x1][0x0] * divCoeff, mat.m_mat[0x1][0x1] * divCoeff, mat.m_mat[0x1][0x2] * divCoeff,
				  		   		 mat.m_mat[0x2][0x0] * divCoeff, mat.m_mat[0x2][0x1] * divCoeff, mat.m_mat[0x2][0x2] * divCoeff );
	}

	template<typename T>
	inline T&& FF::Matrix3x3<T>::Determinant(void) const noexcept {
		return (  this->m_mat[0x0][0x0] * (this->m_mat[0x1][0x1] * this->m_mat[0x2][0x2] - this->m_mat[0x1][0x2] * this->m_mat[0x2][0x1])
				- this->m_mat[0x0][0x1] * (this->m_mat[0x1][0x0] * this->m_mat[0x2][0x2] - this->m_mat[0x1][0x2] * this->m_mat[0x2][0x0])
				+ this->m_mat[0x0][0x2] * (this->m_mat[0x1][0x0] * this->m_mat[0x2][0x1] - this->m_mat[0x1][0x1] * this->m_mat[0x2][0x0]) );
	}

	template<typename T>
	inline T&& Determinant(const FF::Matrix3x3<T>& __FF_IN mat){
		return (  mat.m_mat[0x0][0x0] * (mat.m_mat[0x1][0x1] * mat.m_mat[0x2][0x2] - mat.m_mat[0x1][0x2] * mat.m_mat[0x2][0x1])
				- mat.m_mat[0x0][0x1] * (mat.m_mat[0x1][0x0] * mat.m_mat[0x2][0x2] - mat.m_mat[0x1][0x2] * mat.m_mat[0x2][0x0])
				+ mat.m_mat[0x0][0x2] * (mat.m_mat[0x1][0x0] * mat.m_mat[0x2][0x1] - mat.m_mat[0x1][0x1] * mat.m_mat[0x2][0x0]) );
	}

	template<typename T>
	inline FF::Vector3<T> FF::Matrix3x3<T>::operator[](const std::size_t& __FF_IN rowNumber){
		FF_STATIC_ASSERT_MESSAGE(rowNumber < 0x3uL, "Going beyond the vector!");

		return FF::Vector3<T>(this->m_mat[rowNumber][0x0], this->m_mat[rowNumber][0x1], this->m_mat[rowNumber][0x2]);
	}

	template<typename T>
	inline const T& FF::Matrix3x3<T>::operator()(const std::size_t& i, const std::size_t& j){
		FF_STATIC_ASSERT_MESSAGE(i < 0x3uL && j < 0x3uL, "I or J index greater 0x2. Going beyond array bound!");

		return this->m_mat[i][j];
	}

	template<typename T>
	inline std::ostream& operator<<(std::ostream& out, const FF::Matrix3x3<T>& m){
		std::cout << m.m_mat[0x0][0x0] << " | " << m.m_mat[0x0][0x1] << " | " << m.m_mat[0x0][0x2] << std::endl;
		std::cout << m.m_mat[0x1][0x0] << " | " << m.m_mat[0x1][0x1] << " | " << m.m_mat[0x1][0x2] << std::endl;
		std::cout << m.m_mat[0x2][0x0] << " | " << m.m_mat[0x2][0x1] << " | " << m.m_mat[0x2][0x2] << std::endl;

		return out;
	}
};

#endif // FF_MATRIX3X3_HXX_