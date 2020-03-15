#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofEnableDepthTest();

	this->frame.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
}
//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);

	this->face.clear();
	this->frame.clear();

	auto len = 20;
	for (auto x = -150; x <= 150; x += len) {

		for (auto y = -150; y <= 150; y += len) {

			for (auto z = -150; z <= 150; z += len) {

				this->setBoxToMesh(this->face, this->frame, glm::vec3(x, y, z), len * 0.8);
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum() * 0.5);

	this->face.draw();
	this->frame.drawWireframe();	

	this->cam.end();
}

//--------------------------------------------------------------
void ofApp::setBoxToMesh(ofMesh& face_target, ofMesh& frame_target, glm::vec3 location, float size) {

	this->setBoxToMesh(face_target, frame_target, location, size, size, size);
}

//--------------------------------------------------------------
void ofApp::setBoxToMesh(ofMesh& face_target, ofMesh& frame_target, glm::vec3 location, float height, float width, float depth) {

	int face_index = face_target.getNumVertices();
	int frame_index = frame_target.getNumVertices();

	auto noise_value = ofNoise(glm::vec4(location * 0.008, ofGetFrameNum() * 0.005));
	auto fill = false;

	if (noise_value > 0.75) {

		fill = true;

		face_target.addVertex(location + glm::vec3(width * -0.5 * 0.99, height * 0.5 * 0.99, depth * -0.5 * 0.99));
		face_target.addVertex(location + glm::vec3(width * 0.5 * 0.99, height * 0.5 * 0.99, depth * -0.5 * 0.99));
		face_target.addVertex(location + glm::vec3(width * 0.5 * 0.99, height * 0.5 * 0.99, depth * 0.5 * 0.99));
		face_target.addVertex(location + glm::vec3(width * -0.5 * 0.99, height * 0.5 * 0.99, depth * 0.5 * 0.99));

		face_target.addVertex(location + glm::vec3(width * -0.5 * 0.99, height * -0.5 * 0.99, depth * -0.5 * 0.99));
		face_target.addVertex(location + glm::vec3(width * 0.5 * 0.99, height * -0.5 * 0.99, depth * -0.5 * 0.99));
		face_target.addVertex(location + glm::vec3(width * 0.5 * 0.99, height * -0.5 * 0.99, depth * 0.5 * 0.99));
		face_target.addVertex(location + glm::vec3(width * -0.5 * 0.99, height * -0.5 * 0.99, depth * 0.5 * 0.99));

		face_target.addIndex(face_index + 0); face_target.addIndex(face_index + 1); face_target.addIndex(face_index + 2);
		face_target.addIndex(face_index + 0); face_target.addIndex(face_index + 2); face_target.addIndex(face_index + 3);

		face_target.addIndex(face_index + 4); face_target.addIndex(face_index + 5); face_target.addIndex(face_index + 6);
		face_target.addIndex(face_index + 4); face_target.addIndex(face_index + 6); face_target.addIndex(face_index + 7);

		face_target.addIndex(face_index + 0); face_target.addIndex(face_index + 4); face_target.addIndex(face_index + 1);
		face_target.addIndex(face_index + 4); face_target.addIndex(face_index + 5); face_target.addIndex(face_index + 1);

		face_target.addIndex(face_index + 1); face_target.addIndex(face_index + 5); face_target.addIndex(face_index + 6);
		face_target.addIndex(face_index + 6); face_target.addIndex(face_index + 2); face_target.addIndex(face_index + 1);

		face_target.addIndex(face_index + 2); face_target.addIndex(face_index + 6); face_target.addIndex(face_index + 7);
		face_target.addIndex(face_index + 7); face_target.addIndex(face_index + 3); face_target.addIndex(face_index + 2);

		face_target.addIndex(face_index + 3); face_target.addIndex(face_index + 7); face_target.addIndex(face_index + 4);
		face_target.addIndex(face_index + 4); face_target.addIndex(face_index + 0); face_target.addIndex(face_index + 3);

		for (int i = 0; i < 8; i++) {

			face_target.addColor(ofColor(39));
		}
	}

	if (noise_value > 0.65) {

		frame_target.addVertex(location + glm::vec3(width * -0.5, height * 0.5, depth * -0.5));
		frame_target.addVertex(location + glm::vec3(width * 0.5, height * 0.5, depth * -0.5));
		frame_target.addVertex(location + glm::vec3(width * 0.5, height * 0.5, depth * 0.5));
		frame_target.addVertex(location + glm::vec3(width * -0.5, height * 0.5, depth * 0.5));

		frame_target.addVertex(location + glm::vec3(width * -0.5, height * -0.5, depth * -0.5));
		frame_target.addVertex(location + glm::vec3(width * 0.5, height * -0.5, depth * -0.5));
		frame_target.addVertex(location + glm::vec3(width * 0.5, height * -0.5, depth * 0.5));
		frame_target.addVertex(location + glm::vec3(width * -0.5, height * -0.5, depth * 0.5));

		frame_target.addIndex(frame_index + 0); frame_target.addIndex(frame_index + 1);
		frame_target.addIndex(frame_index + 1); frame_target.addIndex(frame_index + 2);
		frame_target.addIndex(frame_index + 2); frame_target.addIndex(frame_index + 3);
		frame_target.addIndex(frame_index + 3); frame_target.addIndex(frame_index + 0);

		frame_target.addIndex(frame_index + 4); frame_target.addIndex(frame_index + 5);
		frame_target.addIndex(frame_index + 5); frame_target.addIndex(frame_index + 6);
		frame_target.addIndex(frame_index + 6); frame_target.addIndex(frame_index + 7);
		frame_target.addIndex(frame_index + 7); frame_target.addIndex(frame_index + 4);

		frame_target.addIndex(frame_index + 0); frame_target.addIndex(frame_index + 4);
		frame_target.addIndex(frame_index + 1); frame_target.addIndex(frame_index + 5);
		frame_target.addIndex(frame_index + 2); frame_target.addIndex(frame_index + 6);
		frame_target.addIndex(frame_index + 3); frame_target.addIndex(frame_index + 7);

		for (int i = 0; i < 8; i++) {

			frame_target.addColor(fill ? ofColor(239) : ofColor(39));
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}