float iTime;
float Scale;
float2 Offset;
float Intensivity; 
float TimeSpeed;

float4 main(in float2 uv: TEXCOORD0): SV_TARGET
{
    uv.x += iTime * TimeSpeed;
    float x = pow(1.0 - abs(sin(uv.x * Scale + Offset.x) - (uv.y * Scale + Offset.y)), (1.0 / Intensivity));
    return float4(0,x,0.1,0);
}