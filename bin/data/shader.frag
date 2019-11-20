//
//  basic fragment shader --
//      color spectrum based on texture coords

#version 120        // we are using OpenGL 2.1 (oF default)

#define pi 3.14159265359

// from vertex shader:
varying vec2 texCoordVarying;       // texture coords

void main()
{
    
    vec2 tc    = texCoordVarying;   // should be 0-1 range
    
    //  map to color values (also 0-1)
    // float r = map(sin(pi * texCoordVarying.x), 0.f, 1.f, 0.6f, 1.f);
    float r = 0.6f + (sin(pi * texCoordVarying.x)) * 0.4f;
    //float g = cos(pi * texCoordVarying.y);
    float g = 0.6f + (cos(pi * texCoordVarying.y)) * 0.4f;
    float b = 1.0f;
    vec4 color = vec4(r, g, b, 1.0f);
    
    // assign color to our pixel
    gl_FragColor    = color;
    
}

float map(float value, float min1, float max1, float min2, float max2) {
	return min2 + (value - min1) * (max2 - min2) / (max1 - min1);
}



