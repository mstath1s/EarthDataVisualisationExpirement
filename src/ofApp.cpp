#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
    
    //setup window
    ofSetWindowShape(500,500);
    ofSetWindowPosition(0,0);
    ofBackground(0);
    
    ofSetFrameRate(20);
    
    //load textures with normalized texcoords (0..1)
    ofDisableArbTex();
    earth.loadImage("earth2k.jpg");
    clouds.loadImage("clouds.jpg");
    
    //load the vertex and fragment shaders
    shader.load("shaders/blend");
    
    //initialize sphere
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, GL_TRUE);
    gluQuadricNormals(quadric, GLU_SMOOTH);
}

//--------------------------------------------------------------
void ofApp::update(){
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //start camera and flip y-axis
    cam.begin();
    ofScale(1,-1);
    
    //start shader en set uniform variables
    shader.begin();
    shader.setUniformTexture("earth", earth, 1);
    shader.setUniformTexture("clouds", clouds, 2);
    shader.setUniform1f("blendAlpha", sin(ofGetElapsedTimef())/2+.5); //fade clouds
    
    //draw sphere
    glEnable(GL_DEPTH_TEST);
    gluSphere(quadric, 150, 400, 400);
    
    //that's all
    shader.end();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
