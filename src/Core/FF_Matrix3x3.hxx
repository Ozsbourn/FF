#include "FF_Macros.hxx"
#include "FF_Vector3.hxx"

#ifndef FF_MATRIX3X3_HXX_
#define FF_MATRIX3X3_HXX_

namespace FF {
	template<typename T>
	class Matrix3x3 {
	private:
		T m_mat[0x3][0x3];
	public:
		explicit Matrix3x3(void) = delete;

		explicit Matrix3x3(	T __FF_IN v11 = static_cast<T>(0.0f), T __FF_IN v12 = static_cast<T>(0.0f), T __FF_IN v13 = static_cast<T>(0.0f),
							T __FF_IN v21 = static_cast<T>(0.0f), T __FF_IN v22 = static_cast<T>(0.0f), T __FF_IN v23 = static_cast<T>(0.0f),
							T __FF_IN v31 = static_cast<T>(0.0f), T __FF_IN v32 = static_cast<T>(0.0f), T __FF_IN v33 = static_cast<T>(0.0f) )
		: m_mat{ v11, v12, v13,
		 		 v21, v22, v23,
		 		 v31, v32, v33 } {}

		explicit Matrix3x3( FF::Vector3<T>& __FF_IN vec1,
							FF::Vector3<T>& __FF_IN vec2,
							FF::Vector3<T>& __FF_IN vec3 );

		template<typename U>
		friend inline FF::Matrix3x3<U>& Identity(void);

		inline void operator-=(const T& __FF_IN scalar);
		inline void operator+=(const T& __FF_IN scalar);
		inline void operator*=(const T& __FF_IN scalar);
		inline void operator/=(const T& __FF_IN scalar);

		inline void operator-=(const FF::Matrix3x3<T>& __FF_IN mat);
		inline void operator+=(const FF::Matrix3x3<T>& __FF_IN mat);

		template<typename U>
		friend inline FF::Matrix3x3<U> operator-(const FF::Matrix3x3<U>& __FF_IN mat);
		template<typename U>
		friend inline FF::Matrix3x3<U> operator-(const FF::Matrix3x3<U>& __FF_IN mat1, const FF::Matrix3x3<U>& __FF_IN mat2);
		template<typename U>
		friend inline FF::Matrix3x3<U> operator+(const FF::Matrix3x3<U>& __FF_IN mat1, const FF::Matrix3x3<U>& __FF_IN mat2);
		template<typename U>
		friend inline FF::Matrix3x3<U> operator*(const FF::Matrix3x3<U>& __FF_IN mat1, const FF::Matrix3x3<U>& __FF_IN mat2);

		template<typename U>
		friend inline FF::Vector3<U>   operator*(const FF::Matrix3x3<U>& __FF_IN mat,  const FF::Vector3<U>& __FF_IN vec);

		template<typename U>
		friend inline FF::Matrix3x3<U> operator-(const FF::Matrix3x3<U>& __FF_IN mat,  const U& __FF_IN scalar);
		template<typename U>
		friend inline FF::Matrix3x3<U> operator+(const FF::Matrix3x3<U>& __FF_IN mat,  const U& __FF_IN scalar);
		template<typename U>
		friend inline FF::Matrix3x3<U> operator*(const FF::Matrix3x3<U>& __FF_IN mat,  const U& __FF_IN scalar);
		template<typename U>
		friend inline FF::Matrix3x3<U> operator/(const FF::Matrix3x3<U>& __FF_IN mat,  const U& __FF_IN scalar);

		inline T&& 	      Determinant(void) const;
		template<typename U>
		friend inline U&& Determinant(const FF::Matrix3x3<U>& __FF_IN mat);

		inline FF::Vector3<T>  operator[](const std::size_t& __FF_IN rowNumber);
		inline const T&        operator()(const std::size_t& __FF_IN i, const std::size_t& __FF_IN j) const;

		template<typename U>
		friend inline std::ostream& operator<<(std::ostream& __FF_OUT out, const FF::Matrix3x3<U>& __FF_IN m);

		~Matrix3x3(void) = default;
	};

	template<typename T>
	FF::Matrix3x3<T>::Matrix3x3( FF::Vector3<T>& __FF_IN vec1,
						 	     FF::Vector3<T>& __FF_IN vec2,
						 	     FF::Vector3<T>& __FF_IN vec3 )
	: m_mat{ vec1.getXComponent(), vec1.getYComponent(), vec1.GetZComponent(),
		 	 vec2.getXComponent(), vec2.getYComponent(), vec2.GetZComponent(),
		 	 vec3.getXComponent(), vec3.getYComponent(), vec3.GetZComponent() } {}

	template<typename T>
	inline FF::Matrix3x3<T>& Identity(void){
		return FF::Matrix3x3<T>( static_cast<T>(1.0f), static_cast<T>(0.0f), static_cast<T>(0.0f),
				  		  	     static_cast<T>(0.0f), static_cast<T>(1.0f), static_cast<T>(0.0f),
				  		   		 static_cast<T>(0.0f), static_cast<T>(0.0f), static_cast<T>(1.0f) );
	}

	template<typename T>
	inline void FF::Matrix3x3<T>::operator-=(const T& __FF_IN scalar){
		this->m_mat[0x0][0x0] -= scalar; this->m_mat[0x0][0x1] -= scalar; this->m_mat[0x0][0x2] -= scalar;
		this->m_mat[0x1][0x0] -= scalar; this->m_mat[0x1][0x1] -= scalar; this->m_mat[0x1][0x2] -= scalar;
		this->m_mat[0x2][0x0] -= scalar; this->m_mat[0x2][0x1] -= scalar; this->m_mat[0x2][0x2] -= scalar;
	}

	template<typename T>
	inline void FF::Matrix3x3<T>::operator+=(const T& __FF_IN scalar){
		this->m_mat[0x0][0x0] += scalar; this->m_mat[0x0][0x1] += scalar; this->m_mat[0x0][0x2] += scalar;
		this->m_mat[0x1][0x0] += scalar; this->m_mat[0x1][0x1] += scalar; this->m_mat[0x1][0x2] += scalar;
		this->m_mat[0x2][0x0] += scalar; this->m_mat[0x2][0x1] += scalar; this->m_mat[0x2][0x2] += scalar;
	}

	template<typename T>
	inline void FF::Matrix3x3<T>::operator*=(const T& __FF_IN scalar){
		this->m_mat[0x0][0x0] *= scalar; this->m_mat[0x0][0x1] *= scalar; this->m_mat[0x0][0x2] *= scalar;
		this->m_mat[0x1][0x0] *= scalar; this->m_mat[0x1][0x1] *= scalar; this->m_mat[0x1][0x2] *= scalar;
		this->m_mat[0x2][0x0] *= scalar; this->m_mat[0x2][0x1] *= scalar; this->m_mat[0x2][0x2] *= scalar;
	}

	template<typename T>
	inline void FF::Matrix3x3<T>::operator-=(const FF::Matrix3x3<T>& __FF_IN mat){
		this->m_mat[0x0][0x0] -= mat.m_mat[0x0][0x0]; this->m_mat[0x0][0x1] -= mat.m_mat[0x0][0x1]; this->m_mat[0x0][0x2] -= mat.m_mat[0x0][0x2];
		this->m_mat[0x1][0x0] -= mat.m_mat[0x1][0x0]; this->m_mat[0x1][0x1] -= mat.m_mat[0x1][0x1]; this->m_mat[0x1][0x2] -= mat.m_mat[0x1][0x2];
		this->m_mat[0x2][0x0] -= mat.m_mat[0x2][0x0]; this->m_mat[0x2][0x1] -= mat.m_mat[0x2][0x1]; this->m_mat[0x2][0x2] -= mat.m_mat[0x2][0x2];
	}

	template<typename T>
	inline void FF::Matrix3x3<T>::operator+=(const FF::Matrix3x3<T>& __FF_IN mat){
		this->m_mat[0x0][0x0] += mat.m_mat[0x0][0x0]; this->m_mat[0x0][0x1] += mat.m_mat[0x0][0x1]; this->m_mat[0x0][0x2] += mat.m_mat[0x0][0x2];
		this->m_mat[0x1][0x0] += mat.m_mat[0x1][0x0]; this->m_mat[0x1][0x1] += mat.m_mat[0x1][0x1]; this->m_mat[0x1][0x2] += mat.m_mat[0x1][0x2];
		this->m_mat[0x2][0x0] += mat.m_mat[0x2][0x0]; this->m_mat[0x2][0x1] += mat.m_mat[0x2][0x1]; this->m_mat[0x2][0x2] += mat.m_mat[0x2][0x2];
	}

	template<typename T>
	inline void FF::Matrix3x3<T>::operator/=(const T& __FF_IN scalar){
		T divCoeff = 0x1 / scalar;
		this->m_mat[0x0][0x0] *= divCoeff; this->m_mat[0x0][0x1] *= divCoeff; this->m_mat[0x0][0x2] *= divCoeff;
		this->m_mat[0x1][0x0] *= divCoeff; this->m_mat[0x1][0x1] *= divCoeff; this->m_mat[0x1][0x2] *= divCoeff;
		this->m_mat[0x2][0x0] *= divCoeff; this->m_mat[0x2][0x1] *= divCoeff; this->m_mat[0x2][0x2] *= divCoeff;
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
		T divCoeff = 0x1 / scalar;
		return FF::Matrix3x3<T>( mat.m_mat[0x0][0x0] * divCoeff, mat.m_mat[0x0][0x1] * divCoeff, mat.m_mat[0x0][0x2] * divCoeff,
				  		   		 mat.m_mat[0x1][0x0] * divCoeff, mat.m_mat[0x1][0x1] * divCoeff, mat.m_mat[0x1][0x2] * divCoeff,
				  		   		 mat.m_mat[0x2][0x0] * divCoeff, mat.m_mat[0x2][0x1] * divCoeff, mat.m_mat[0x2][0x2] * divCoeff );
	}

	template<typename T>
	inline T&& FF::Matrix3x3<T>::Determinant(void) const {
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
		assert(rowNumber < 0x3uL && "Going beyond the vector!");
		return FF::Vector3<T>(this->m_mat[rowNumber][0x0], this->m_mat[rowNumber][0x1], this->m_mat[rowNumber][0x2]);
	}

	template<typename T>
	inline const T& FF::Matrix3x3<T>::operator()(const std::size_t& i, const std::size_t& j) const {
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