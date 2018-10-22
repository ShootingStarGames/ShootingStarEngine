#pragma once

#define SAFE_DELETE(x)				{ if(x){ delete x; x = nullptr; } }
#define SAFE_DELETE_ARRAY(x)		{ if(x){ delete[] x; x = nullptr; } }
#define SAFE_RELEASE(x)				{ if(x){ x->Release(); x = nullptr; } }
#define SAFE_DESTROY_DELTE(x)		{ if(x){ x->Destroy(); delete x; x = nullptr; } }

#define DECLARE_SINGLE(Type)	\
	private:\
		static Type* m_pInst;	\
	public:\
		static Type* GetInst()	\
	{\
		if(!m_pInst)\
			m_pInst = new Type;\
		return m_pInst;\
	}\
	static void DestroyInst()\
	{\
		SAFE_DELETE(m_pInst);\
	}\
	private:\
		Type();\
		~Type();

#define DEFINITION_SINGLE(Type) Type* Type::m_pInst = NULL;
#define GET_SINGLE(Type)		Type::GetInst()
#define DESTROY_SINGLE(Type)	Type::DestroyInst()

typedef unsigned int		uint;
typedef unsigned short int	ushort;
typedef unsigned char		uchar;