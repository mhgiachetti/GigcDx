
float4x4 matWorldViewProj;

texture base_Tex;
sampler2D baseMap =
sampler_state
{
   Texture = (base_Tex);
   MINFILTER = ANISOTROPIC  ;
   MAGFILTER = ANISOTROPIC  ;
   MIPFILTER = ANISOTROPIC  ;
};


void VertexDefault(	float4 iPos: POSITION,
										float2 iuv: TEXCOORD0,
										out float4 oPos: POSITION,
										out float2 ouv:TEXCOORD0)
{
	oPos = mul(matWorldViewProj, iPos);
	ouv = iuv;
}

float4 PixelDefault(float2 uv : TEXCOORD0) : COLOR
{
  return tex2D(baseMap,uv);
}


technique Default
{
	pass p0
	{
		VertexShader = compile vs_2_0 VertexDefault();
		PixelShader = compile ps_2_0 PixelDefault();
	}
}



