//
//  basic fragment shader --
//      color spectrum based on texture coords

#version 120        // we are using OpenGL 2.1 (oF default)

#define pi 3.14159265359

// from vertex shader:
varying vec2 texCoordVarying;       // texture coords

// from ofApp
uniform float time;

void main()
{
    
    vec2 tc    = texCoordVarying;   // should be 0-1 range
    
    //  map to color values (also 0-1)
    // float r = map(sin(pi * texCoordVarying.x), 0.f, 1.f, 0.6f, 1.f);
    float r = 0.6f + (sin(time/100.f + pi * texCoordVarying.x)) * 0.4f;
    //float g = cos(pi * texCoordVarying.y);
    float g = 0.6f + (cos(time/100.f + pi * texCoordVarying.y)) * 0.4f;
    float b = 1.0f;
    vec4 color = vec4(r, g, b, 1.0f);
    
    // assign color to our pixel
    gl_FragColor    = color;
    
}
