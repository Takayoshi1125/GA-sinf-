
struct  Vector2{
	float x, y;
	Vector2() :x(0.0f),y(0.0f){}
	Vector2(float inx, float iny) :x(inx), y(iny) {};
	void operator+=(const Vector2& vec);
	void operator-=(const Vector2& vec);
	void operator*=(float scale);
	void operator/=(float div);
	bool operator== (const Vector2& vec)const;
	/// <summary>
	/// �x�N�g���̑傫����Ԃ�
	/// </summary>
	/// <returns>�x�N�g���̑傫��</returns>
	float Magnitude()const;

	/// <summary>
	/// �x�N�g���̑傫����2���Ԃ�(������SQRT���Ȃ�)
	/// </summary>
	/// <returns>�x�N�g���̑傫����2��</returns>
	float SQMagnitude()const;

	/// <summary>
	/// �x�N�g���𐳋K������(�傫����1�ɂ���)
	/// </summary>
	void Normalize();

	/// <summary>
	/// ���K���x�N�g����Ԃ�
	/// </summary>
	/// <returns>���K���x�N�g��</returns>
	Vector2 Normalized()const;

	/// <summary>
	/// �x�N�g����90���Ȃ���
	/// </summary>
	void Rotate90();


	Vector2 Rotated90()const;
};

Vector2 operator+(const Vector2& lval, const Vector2& rval);
Vector2 operator-(const Vector2& lval, const Vector2& rval);
Vector2 operator*(const Vector2& lval, float scale);
Vector2 operator/(const Vector2& lval, float div);


using Position2 = Vector2;