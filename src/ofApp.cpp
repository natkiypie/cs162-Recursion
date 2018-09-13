#include "ofApp.h"

float xDeg = 90;
float yDeg = 0;
float angle = 15;
float len = 0;

void ofApp::setup() {
  moneyTrees.load("moneytrees.mp3");
  moneyTrees.play();
  deface.load("deface.ttf", 90, true, true, true);
  ofSetBackgroundColor(0, 0, 0);
}

void ofApp::update() {
  xDeg -= 0.5;
  if (xDeg <= 0) {
    xDeg = 0;
    yDeg -= 0.8;
    if (yDeg <= -180) {
      yDeg = -180;
      angle += 0.03;
      len += 0.08;
      if (len >= 50) {
        len = 50;
      }
    }
  }
}

void ofApp::draw() {
  concentricCircles(0, 0, 200, 255, xDeg, yDeg);
  if (yDeg <= -180) {
    ofSetLineWidth(4);
    ofSetColor(0, 0, 0);
    ofTranslate((ofGetWidth() / 2), ((ofGetHeight() / 2) - 50));
    branch(len);
  }
  if (ofGetElapsedTimef() >= 27.8) {
    tag();
  }
}

void ofApp::concentricCircles(int x, int y, int radius, int color, float xDeg, float yDeg) {
  if (radius >= 0) {
    ofSetCircleResolution(80);
    ofSetColor(color);
    ofPushMatrix();
    ofTranslate((ofGetWidth() / 2), ((ofGetHeight() / 2) - 50));
    ofRotateYDeg(yDeg);
    ofDrawCircle(x, y, radius);
    ofPopMatrix();
    ofRotateXDeg(xDeg);
    concentricCircles(x, y, (radius - 10), (color - 10), xDeg, yDeg);
  }
}

void ofApp::branch(int len) {
  ofDrawLine(0, 0, 0, -len);
  ofTranslate(0, -len);
  if (len > 0 && ofGetElapsedTimef() < 387) {
    ofPushMatrix();
    ofRotateDeg(angle);
    branch(len * 0.75);
    ofPopMatrix();
    ofPushMatrix();
    ofRotateDeg(-angle);
    branch(len * 0.75);
    ofPopMatrix();
  }
}

void ofApp::tag() {
  ofSetColor(200, 200, 200);
  deface.drawString("Recursion.", -320, 360);
}

void ofApp::keyPressed(int key) {
}

void ofApp::keyReleased(int key) {
}

void ofApp::mouseMoved(int x, int y ) {
}

void ofApp::mouseDragged(int x, int y, int button) {
}

void ofApp::mousePressed(int x, int y, int button) {
}

void ofApp::mouseReleased(int x, int y, int button) {
}

void ofApp::mouseEntered(int x, int y) {
}

void ofApp::mouseExited(int x, int y) {
}

void ofApp::windowResized(int w, int h) {
}

void ofApp::gotMessage(ofMessage msg) {
}

void ofApp::dragEvent(ofDragInfo dragInfo) { 
}
