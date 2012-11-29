// CustomVertex.h: interface for the CustomVertex class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CUSTOMVERTEX_H__8FF90842_7E72_4E4B_A6F7_68D4C2CCB753__INCLUDED_)
#define AFX_CUSTOMVERTEX_H__8FF90842_7E72_4E4B_A6F7_68D4C2CCB753__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "globalDefines.h"

namespace CustomVertex  
{
	typedef struct  
	{
		float x;
		float y;
		float z;
		int color;
		public:
			static int Size() {return sizeof(PositionColored);};
			static VertexFormat Format() {return VertexFormat_Position | VertexFormat_Diffuse;};

	}PositionColored;

	typedef struct  
	{
		float x;
		float y;
		float z;
		float nx;
		float ny;
		float nz;

		public:
			static int Size() {return sizeof(PositionNormal);};
			static VertexFormat Format() {return VertexFormat_PositionNormal;};
	}PositionNormal;


	typedef struct  
	{
		float x;
		float y;
		float z;
		float nx;
		float ny;
		float nz;
		int color;
		
		public:
			static int Size() {return sizeof(PositionNormalColored);};
			static VertexFormat Format() {return VertexFormat_PositionNormal | VertexFormat_Diffuse;};
	}PositionNormalColored;

	typedef struct  
	{
		float x;
		float y;
		float z;
		float u;
		float v;
		
		public:
			static int Size() {return sizeof(PositionTextured);};
			static VertexFormat Format() {return VertexFormat_Position | VertexFormat_Texture1;};
	}PositionTextured;

	typedef struct  
	{
		float x;
		float y;
		float z;
		float nx;
		float ny;
		float nz;
		float u;
		float v;
		
		public:
			static int Size() {return sizeof(PositionNormalTextured);};
			static VertexFormat Format() {return VertexFormat_PositionNormal | VertexFormat_Texture1;};
	}PositionNormalTextured;


	typedef struct  
	{
		float x;
		float y;
		float z;
		float rhw;
		int color;
		public:
			static int Size() {return sizeof(TransformedColored);};
			static VertexFormat Format() {return VertexFormat_Transformed | VertexFormat_Diffuse;};
			
	}TransformedColored;

	
}

#endif // !defined(AFX_CUSTOMVERTEX_H__8FF90842_7E72_4E4B_A6F7_68D4C2CCB753__INCLUDED_)
