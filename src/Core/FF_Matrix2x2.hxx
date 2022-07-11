#include "FF_Macros.hxx"
#include "FF_Vector2.hxx"

#ifndef FF_MATRIX2X2_HXX_
#define FF_MATRIX2X2_HXX_

namespace FF {
	template<typename T>
	class Matrix2x2 {
	private:
		T m_mat[0x2][0x2];
	public:
		explicit Matrix2x2(void) = delete;

		explicit Matrix2x2(	T __FF_IN v11 = static_cast<T>(0.0f), 
							T __FF_IN v12 = static_cast<T>(0.0f),
							T __FF_IN v21 = static_cast<T>(0.0f), 
							T __FF_IN v22 = static_cast<T>(0.0f) )
		: m_mat{ v11, v12,
		 	 	 v21, v22 } {}

		explicit Matrix2x2( FF::Vector2<T>& __FF_IN vec1,
							FF::Vector2<T>& __FF_IN vec2 );

		template<typename U>
		friend inline FF::Matrix2x2<U>& Identity(void);

		inline void operator-=(const T& __FF_IN scalar);
		inline void operator+=(const T& __FF_IN scalar);
		inline void operator*=(const T& __FF_IN scalar);
		inline void operator/=(const T& __FF_IN scalar);

		inline void operator-=(const FF::Matrix2x2<T>& __FF_IN mat);
		inline void operator+=(const FF::Matrix2x2<T>& __FF_IN mat);

		template<typename U>
		friend inline FF::Matrix2x2<U> operator-(const FF::Matrix2x2<U>& __FF_IN mat);
		template<typename U>
		friend inline FF::Matrix2x2<U> operator-(const FF::Matrix2x2<U>& __FF_IN mat1, const FF::Matrix2x2<U>& __FF_IN mat2);
		template<typename U>
		friend inline FF::Matrix2x2<U> operator+(const FF::Matrix2x2<U>& __FF_IN mat1, const FF::Matrix2x2<U>& __FF_IN mat2);
		template<typename U>
		friend inline FF::Matrix2x2<U> operator*(const FF::Matrix2x2<U>& __FF_IN mat1, const FF::Matrix2x2<U>& __FF_IN mat2);

		template<typename U>
		friend inline FF::Vector2<U>   operator*(const Matrix2x2& __FF_IN mat,  const FF::Vector2<U>& __FF_IN vec);

		template<typename U>
		friend inline FF::Matrix2x2<U> operator-(const FF::Matrix2x2<U>& __FF_IN mat,  const U& __FF_IN scalar);
		template<typename U>
		friend inline FF::Matrix2x2<U> operator+(const FF::Matrix2x2<U>& __FF_IN mat,  const U& __FF_IN scalar);
		template<typename U>
		friend inline FF::Matrix2x2<U> operator*(const FF::Matrix2x2<U>& __FF_IN mat,  const U& __FF_IN scalar);
		template<typename U>
		friend inline FF::Matrix2x2<U> operator/(const FF::Matrix2x2<U>& __FF_IN mat,  const U& __FF_IN scalar);

		inline T&& 	      Determinant(void) const;
		template<typename U>
		friend inline U&& Determinant(const FF::Matrix2x2<U>& __FF_IN mat);

		inline FF::Vector2<T> operator[](const std::size_t& __FF_IN rowNumber);

		template<typename U>
		friend inline std::ostream& operator<<(std::ostream& out, const FF::Matrix2x2<U>& m);

		~Matrix2x2(void) = default;
	};	

	template<typename T>
	FF::Matrix2x2<T>::Matrix2x2( FF::Vector2<T>& __FF_IN vec1,
					      		 FF::Vector2<T>& __FF_IN vec2 )
	: m_mat{ vec1.getXComponent(vec1), vec1.getYComponent(vec1),
		 	 vec2.getXComponent(vec2), vec2.getYComponent(vec2) } {}

	template<typename T>
	inline FF::Matrix2x2<T>& Identity(void){
		return FF::Matrix2x2<T>( static_cast<T>(1.0f), static_cast<T>(0.0f),
				  	 			 static_cast<T>(0.0f), static_cast<T>(1.0f) );
	}

	template<typename T>
	inline void FF::Matrix2x2<T>::operator-=(const T& __FF_IN scalar){
		this->m_mat[0x0][0x0] -= scalar; this->m_mat[0x0][0x1] -= scalar;
		this->m_mat[0x1][0x0] -= scalar; this->m_mat[0x1][0x1] -= scalar;
	}

	template<typename T>
	inline void FF::Matrix2x2<T>::operator+=(const T& __FF_IN scalar){
		this->m_mat[0x0][0x0] += scalar; this->m_mat[0x0][0x1] += scalar;
		this->m_mat[0x1][0x0] += scalar; this->m_mat[0x1][0x1] += scalar;
	}

	template<typename T>
	inline void FF::Matrix2x2<T>::operator*=(const T& __FF_IN scalar){
		this->m_mat[0x0][0x0] *= scalar; this->m_mat[0x0][0x1] *= scalar; 
		this->m_mat[0x1][0x0] *= scalar; this->m_mat[0x1][0x1] *= scalar; 
	}

	template<typename T>
	inline void FF::Matrix2x2<T>::operator-=(const FF::Matrix2x2<T>& __FF_IN mat){
		this->m_mat[0x0][0x0] -= mat.m_mat[0x0][0x0]; this->m_mat[0x0][0x1] -= mat.m_mat[0x0][0x1];
		this->m_mat[0x1][0x0] -= mat.m_mat[0x1][0x0]; this->m_mat[0x1][0x1] -= mat.m_mat[0x1][0x1];
	}

	template<typename T>
	inline void FF::Matrix2x2<T>::operator+=(const FF::Matrix2x2<T>& __FF_IN mat){
		this->m_mat[0x0][0x0] += mat.m_mat[0x0][0x0]; this->m_mat[0x0][0x1] += mat.m_mat[0x0][0x1];
		this->m_mat[0x1][0x0] += mat.m_mat[0x1][0x0]; this->m_mat[0x1][0x1] += mat.m_mat[0x1][0x1];
	}

	template<typename T>
	inline void FF::Matrix2x2<T>::operator/=(const T& __FF_IN scalar){
		T divCoeff = 0x1 / scalar;
		this->m_mat[0x0][0x0] *= divCoeff; this->m_mat[0x0][0x1] *= divCoeff;
		this->m_mat[0x1][0x0] *= divCoeff; this->m_mat[0x1][0x1] *= divCoeff;
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
		return   FF::Vector2<T>( mat.m_mat[0x0][0x0] * vec.getXComponent(vec) + mat.m_mat[0x0][0x1] * vec.getYComponent(vec),
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
		T divCoeff = 0x1 / scalar;
		return FF::Matrix2x2<T>( mat.m_mat[0x0][0x0] * divCoeff, mat.m_mat[0x0][0x1] * divCoeff,
				  	 mat.m_mat[0x1][0x0] * divCoeff, mat.m_mat[0x1][0x1] * divCoeff );
	}

	template<typename T>
	inline T&& FF::Matrix2x2<T>::Determinant(void) const {
		return ( this->m_mat[0x0][0x0] * this->m_mat[0x1][0x1] - this->m_mat[0x0][0x1] * this->m_mat[0x1][0x0] );
	}

	template<typename T>
	inline T&& Determinant(const FF::Matrix2x2<T>& __FF_IN mat){
		return ( mat.m_mat[0x0][0x0] * mat.m_mat[0x1][0x1] - mat.m_mat[0x0][0x1] * mat.m_mat[0x1][0x0] );
	}

	template<typename T>
	inline FF::Vector2<T> FF::Matrix2x2<T>::operator[](const std::size_t& __FF_IN rowNumber){
		assert(rowNumber < 0x2uL && "Going beyond the vector!");
		return FF::Vector2<T>(m_mat[rowNumber][0x0], m_mat[rowNumber][0x1]);
	}

	template<typename T>
	inline std::ostream& operator<<(std::ostream& out, const FF::Matrix2x2<T>& m){
		std::cout << m.m_mat[0x0][0x0] << " | " << m.m_mat[0x0][0x1] << std::endl;
		std::cout << m.m_mat[0x1][0x0] << " | " << m.m_mat[0x1][0x1] << std::endl;

		return out;
	}
};

#endif // FF_MATRIX2X2_HXX_