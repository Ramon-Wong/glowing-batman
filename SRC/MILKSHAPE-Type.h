#ifndef _MILKSHAPE_TYPE_H
#define _MILKSHAPE_TYPE_H

#include <stdio.h>
#include <string.h>


#define RELEASE(OBJECT) if(OBJECT)  delete [] OBJECT; OBJECT = NULL;
#define CREATE(OBJECT, TYPE, Counts)   OBJECT = new TYPE[Counts];


typedef struct {
	char								Id[10];
	int									Version; 
}MS3D_HEADER;

typedef struct {
	unsigned char						Flags;
	float								Vertex[3];   
	char								BoneId;
	unsigned char						Refcount; 
}MS3D_VERTEX;


typedef struct {
	unsigned short						Flags;
	unsigned short						VertexIndices[3];  
    unsigned short						vIndices[3];
	
	float								VertexNormals[3][3]; 
	float								S[3], T[3]; 
	unsigned char						SmoothingGroup;
	unsigned char						GroupIndex; 
}MS3D_TRIANGLE;


typedef struct {
	unsigned char						Flags;
	char								Name[32];
	unsigned short						NumTriangles; 
	unsigned short					*	TrianglesIndices;  
	char								MaterialIndex;
	
	unsigned short					*	tIndices;  //new indices for Render Elements
}MS3D_MESH;


typedef struct {
	char								Name[32]; 
	float								Ambient[4];
	float								Diffuse[4];
	float								Specular[4];
	float								Emissive[4];  
	float								Transparency;
	float								Shininess; 
	char								Mode;
	
	char								Texture[128];
	char								AlphaMap[128];
}MS3D_MATERIAL;


typedef struct {
	unsigned char						Flags;
	char								Names[32];
	char								ParentName[32];
	float								Rotation[3];
	float								Position[3];
	int									Parent;

	//~ unsigned short						Num_KeyFramesRot;
	//~ unsigned short						Num_KeyFramesTrans;

	//~ MS3D_KEYFRAME					*	KeyFramesRot;
	//~ MS3D_KEYFRAME					*	KeyFramesTrans;
		
	//~ float								KeyFrames[6];
		
	//~ MATRIX								Final;
	//~ MATRIX								Relative;
	//~ MATRIX								Absolute;	
	
	//~ int									CurrentTranslation;
	//~ int									CurrentRotation;		
 
}MS3D_JOINT;


typedef struct {
	int									Index;
	char								Names[32];
}MS3D_JOINTNAME;



#endif
