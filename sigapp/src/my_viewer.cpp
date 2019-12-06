
# include "my_viewer.h"

# include <sigogl/ui_button.h>
# include <sigogl/ui_radio_button.h>
# include <sig/sn_primitive.h>
# include <sig/sn_transform.h>
# include <sig/sn_manipulator.h>
#include <cmath>

# include <sigogl/ws_run.h>

float righthand;
float lefthand;
float leftleg;
float rightleg;
float rad = 2; 
float bigradius = 0;
float resolution = 10;
bool redraw1 = false;
float hhead;
bool flatshading = false;
bool norvec = false;
int control = 1;
SnManipulator* left_leg = new SnManipulator;
SnManipulator* right_leg = new SnManipulator;
SnManipulator* right_hand = new SnManipulator;
SnManipulator* left_hand = new SnManipulator;
SnManipulator* h_head = new SnManipulator;
SnManipulator* h_neck = new SnManipulator;
SnManipulator* h_hips = new SnManipulator;
SnManipulator* h_chest = new SnManipulator;
SnManipulator* persontranslation = new SnManipulator;
float yposition = 0.0f;
float xposition = 0.0f;


MyViewer::MyViewer ( int x, int y, int w, int h, const char* l ) : WsViewer(x,y,w,h,l)
{
	build_ui ();
	build_scene ();
}

void MyViewer::build_ui ()
{
	UiPanel *p, *sp;
	UiManager* uim = WsWindow::uim();
	p = uim->add_panel ( "", UiPanel::HorizLeft );
	p->add ( new UiButton ( "View", sp=new UiPanel() ) );
	{	UiPanel* p=sp;
		p->add ( _nbut=new UiCheckButton ( "Normals", EvNormals ) ); 
	}
	p->add ( new UiButton ( "Animate", EvAnimate ) );
	p->add ( new UiButton ( "Exit", EvExit ) ); p->top()->separate();
}

void MyViewer::add_model ( SnShape* s, GsVec p )
{
	// This method demonstrates how to add some elements to our scene graph: lines,
	// and a shape, and all in a group under a SnManipulator.
	// Therefore we are also demonstrating the use of a manipulator to allow the user to
	// change the position of the object with the mouse. If you do not need mouse interaction,
	// you can just use a SnTransform to apply a transformation instead of a SnManipulator.
	// You would then add the transform as 1st element of the group, and set g->separator(true).
	// Your scene graph should always be carefully designed according to your application needs.


	SnManipulator* manip = new SnManipulator;
	GsMat m;
	m.translation ( p );
	manip->initial_mat ( m );


	SnGroup* g = new SnGroup;
	SnLines* l = new SnLines;
	l->color(GsColor::orange);
	g->add(s);
	g->add(l);
	manip->child(g);
	// manip->visible(false); // call this to turn off mouse interaction


	rootg()->add(manip);
}

void MyViewer::build_scene ()
{
	SnPrimitive* p;
	GsModel* mymodel = new GsModel;
	//bool smooth = true;
	if (redraw1) {
		rootg()->remove(0);
		rootg()->remove(1);
	}
	//bool flat = true;
	double x1, y1, z1;
	double x2, y2, z2;
	double x3, y3, z3;
	double x4, y4, z4;
	double a1, b1;
	double a2, b2;
	double a3, b3;
	double a4, b4;


	int n = 0;
	SnLines* Line = new SnLines;
	Line->init();
	GsPnt A;
	GsPnt B;
	GsPnt C;
	GsPnt D;
	GsPnt E;
	GsPnt F;
	GsPnt G;
	GsPnt H;
	GsPnt normal_A;
	GsPnt normal_B;
	GsPnt normal_C;
	GsPnt normal_D;
	GsVec i;
	GsVec j;
	GsVec k;


	float firstpoint;
	float secondpoint;
	float thirdpoint;
	float firstpoint2;
	float secondpoint2;
	float thirdpoint2;

	double theta = 0;
	double Phi = 0;
	double delta = GS_2PI / (double)resolution;



	GsArray<GsVec> P(0, (int)(resolution * resolution * 4)); // will hold the points forming my triangles (size 0, but pre-allocate 6 spaces)

	//calculate x y and z inside your double forloop
	GsVec point1;
	GsVec point2;
	GsVec point3;
	GsVec point4;
	GsVec point5;
	GsVec point6;
	GsVec point7;
	GsVec point8;


	for (double Theta = 0; Theta < GS_2PI; Theta += delta) {//psuedo code given by TA

		for (double Phi = 0; Phi < GS_2PI; Phi += delta) {

			//this is for A
			x1 = (bigradius + rad * cos((double)Theta)) * cos((double)Phi);
			y1 = (bigradius + rad * cos((double)Theta)) * sin((double)Phi);
			z1 = rad * sin((double)Theta);

			//GsVec p1 = p1.set(x1, y1, z1);
			point1.set(x1, y1, z1);

			//this is for B
			x2 = (bigradius + rad * cos((double)Theta + delta)) * cos((double)Phi);
			y2 = (bigradius + rad * cos((double)Theta + delta)) * sin((double)Phi);
			z2 = rad * sin((double)Theta + delta);


			//GsVec p2 = p2.set(x2, y2, z2);
			point2.set(x2, y2, z2);

			//This is for C

			x3 = (bigradius + rad * cos((double)Theta + delta)) * cos((double)Phi + delta);
			y3 = (bigradius + rad * cos((double)Theta + delta)) * sin((double)Phi + delta);
			z3 = rad * sin((double)Theta + delta);


			//GsVec p3 = p3.set(x3, y3, z3);
			point3.set(x3, y3, z3);


			//this is for D

			x4 = (bigradius + rad * cos((double)Theta)) * cos((double)Phi + delta);
			y4 = (bigradius + rad * cos((double)Theta)) * sin((double)Phi + delta);
			z4 = rad * sin((double)Theta);


			//GsVec p4 = p4.set(x4, y4, z4);
			point4.set(x4, y4, z4);

			//making our vector parameters of the triangle into a POINT
			A = GsVec(x1, y1, z1);
			B = GsVec(x2, y2, z2);
			C = GsVec(x3, y3, z3);
			D = GsVec(x4, y4, z4);

			//pushing the points into mymodel
			mymodel->V.push(D);
			mymodel->V.push(C);
			mymodel->V.push(B);
			//pushing them in the order we want it to show up counterclock wise
			mymodel->V.push(D);
			mymodel->V.push(B);
			mymodel->V.push(A);


			//making new points
			a1 = (Theta / GS_2PI);
			b1 = (Phi / GS_2PI);

			a2 = ((Theta + delta) / GS_2PI);
			b2 = (Phi / GS_2PI);


			a3 = ((Theta + delta) / GS_2PI);
			b3 = ((Phi + delta) / GS_2PI);

			a4 = (Theta / GS_2PI);
			b4 = ((Phi + delta) / GS_2PI);

			E = GsPnt2(a1, b1);
			F = GsPnt2(a2, b2);
			G = GsPnt2(a3, b3);
			H = GsPnt2(a4, b4);

			//pushing points into the Texture
			mymodel->T.push() = H;
			mymodel->T.push() = G;
			mymodel->T.push() = F;

			mymodel->T.push() = H;
			mymodel->T.push() = F;
			mymodel->T.push() = E;


			/*! The triangular face keeps 3 indices to the associated vertex information */
			mymodel->F.push() = GsModel::Face(n, n + 1, n + 2);//add n vertices...
			mymodel->F.push() = GsModel::Face(n + 3, n + 4, n + 5);
			//making three indices for the three vector points in triangle
			//pushing those three indicies into model
			n = n + 6;

			//get the center point of the big phi

			firstpoint = (float)cos(Phi) * bigradius;
			secondpoint = (float)sin(Phi) * bigradius;
			thirdpoint = 0;
			//
			firstpoint2 = (float)cos(Phi + delta) * bigradius;
			secondpoint2 = (float)sin(Phi + delta) * bigradius;
			thirdpoint2 = 0;


			Line->color(GsColor::green);
			//calling smooth shading
			if (flatshading) {
				//mymodel->set_mode(GsModel::Smooth, GsModel::NoMtl);

				////flat normal
				GsPnt flat_center = (A + B + C) / 3.0f;
				GsPnt flat2 = cross(A - C, A - B);

				Line->push(flat_center, flat_center + normalize(flat2));

			}
			else//smooth
			{
				//need to do two center points because we need to get cener points for both traingles
				GsVec center_point = GsVec(firstpoint, secondpoint, thirdpoint);
				GsVec center_point2 = GsVec(firstpoint2, secondpoint2, thirdpoint2);

				normal_A = A - center_point;
				normal_B = B - center_point;
				normal_C = C - center_point2;
				normal_D = D - center_point2;


				mymodel->N.push(normal_D);
				mymodel->N.push(normal_C);
				mymodel->N.push(normal_B);

				mymodel->N.push(normal_D);
				mymodel->N.push(normal_B);
				mymodel->N.push(normal_A);

				Line->push(D, D + normalize(normal_D));
				Line->push(C, C + normalize(normal_C));
				Line->push(B, B + normalize(normal_B));

				Line->push(D, D + normalize(normal_D));
				Line->push(B, B + normalize(normal_B));
				Line->push(A, A + normalize(normal_A));


				mymodel->set_mode(GsModel::Smooth, GsModel::NoMtl);



			}


		}
	}
	SnGroup* person = new SnGroup;//pointer person to SnGroup
	//person->separator(true);
	//his head
	SnPrimitive* hhead = new SnPrimitive(GsPrimitive::Sphere, 1.3f);
	hhead->prim().material.diffuse = GsColor::lightgray;
	t.setrans(0, 5, 6);
	
	SnGroup* _hhead = new SnGroup;
	//_hhead->seperator(true);
	_hhead->add(hhead);//adding primitive into SnGroup
	h_head->child(_hhead);//into manipulator
	person->add(h_head);
	h_head->initial_mat(t);//setting a new matrix to the manipulator
	rootg()->add(h_head);
	
	//neck
	SnPrimitive* hneck = new SnPrimitive(GsPrimitive::Capsule, 0.2f, 0.2f, 0.4f);
	hneck->prim().material.diffuse = GsColor::gray;
	t.setrans(0, -1.5f, 0.3f);


	SnGroup* _hneck = new SnGroup;
	_hneck->separator(true);
	_hneck->add(hneck);
	h_neck->child(_hneck);
	_hhead->add(h_neck);
	h_neck->initial_mat(t);
	//rootg()->add(h_neck);



	//chest
	SnPrimitive* hchest= new SnPrimitive(GsPrimitive::Box, 1.0f, 1.0f, 0.5);
	hchest->prim().material.diffuse = GsColor::orange;
	t.setrans(0, -1.0f, -0.3f);

	SnGroup* _hchest = new SnGroup;
	_hchest->separator(true);
	_hchest->add(hchest);
	h_chest->child(_hchest);
	_hneck->add(h_chest);
	h_chest->initial_mat(t);
	//rootg()->add(h_chest);


	//hips
	SnPrimitive* hhips = new SnPrimitive(GsPrimitive::Box, 0.7f, 0.7f, 0.5f);
	hhips->prim().material.diffuse = GsColor::blue;
	t.setrans(0, -1.7f, 0.0);


	SnGroup* _hhips = new SnGroup;
	_hhips->separator(true);
	_hhips->add(hhips);
	h_hips->child(_hhips);
	_hchest->add(h_hips);
	h_hips->initial_mat(t);
	//rootg()->add(h_hips);


	//left leg
	SnPrimitive* leftleg = new SnPrimitive(GsPrimitive::Capsule, 0.2f, 0.2f, 1.0f);
	leftleg->prim().material.diffuse = GsColor::darkgreen;
	t.setrans(-0.5f, -1.0f, 0.0f);

	SnGroup* _leftleg = new SnGroup;
	_leftleg->separator(true);
	_leftleg->add(leftleg);
	left_leg->child(_leftleg); 
	_hhips->add(left_leg);
	left_leg->initial_mat(t);
	//rootg()->add(left_leg);


	//right leg
	SnPrimitive* rightleg = new SnPrimitive(GsPrimitive::Capsule, 0.2f, 0.2f, 1.0f);
	rightleg->prim().material.diffuse = GsColor::darkgreen;
	t.setrans(0.5f, -1.0f, 0.0f);

	SnGroup* _rightleg = new SnGroup;
	//_rightleg->separator(true);
	_rightleg->add(rightleg);
	right_leg->child(_rightleg);
	_hhips->add(right_leg);
	right_leg->initial_mat(t);
	//rootg()->add(right_leg);



	//left hand
	SnPrimitive* lefthand= new SnPrimitive(GsPrimitive::Capsule, 0.2f, 0.2f, 1.2f);
	lefthand->prim().material.diffuse = GsColor::magenta;
	t.setrans(-1.0f, 0.0f, 0.0f);

	SnGroup* _lefthand = new SnGroup;
	_lefthand ->separator(true);
	_lefthand->add(lefthand);
	left_hand->child(_lefthand);
	_hchest->add(left_hand);
	left_hand->initial_mat(t);
	//rootg()->add(left_hand);

	//right hand
	SnPrimitive* righthand = new SnPrimitive(GsPrimitive::Capsule, 0.2f, 0.2f, 1.2f);
	righthand->prim().material.diffuse = GsColor::magenta;
	t.setrans(1.0f, 0.0f, 0.0f);

	SnGroup* _righthand = new SnGroup;
	_righthand->separator(true);
	_righthand->add(righthand);
	right_hand->child(_righthand);
	_hchest->add(right_hand);
	right_hand->initial_mat(t);
	//rootg()->add(right_hand);



	//tree give it texture later
	p = new SnPrimitive(GsPrimitive::Ellipsoid, 3.0f, 1.0f);
	p->prim().material.diffuse = GsColor::green;
	add_model(p, GsVec(10.0f, 6.0f, -15.0f));

	//tree bottom
	p = new SnPrimitive(GsPrimitive::Capsule, 0.5f, 0.4f, 2.5f);
	p->prim().material.diffuse = GsColor::brown;
	add_model(p, GsVec(10.0f, 1.0f, -15.0f));

	//tree top
	p = new SnPrimitive(GsPrimitive::Ellipsoid, 3.0f, 1.0f);
	p->prim().material.diffuse = GsColor::green;
	add_model(p, GsVec(-10.0f, 6.0f, -15.0f));

	//tree bottom
	p = new SnPrimitive(GsPrimitive::Capsule, 0.5f, 0.4f, 2.5f);
	p->prim().material.diffuse = GsColor::brown;
	add_model(p, GsVec(-10.0f, 1.0f, -15.0f));

	//floor
	p = new SnPrimitive(GsPrimitive::Box, 15.0f, 0.3f, 18.0f);
	p->prim().material.diffuse = GsColor::lightgray;
	add_model(p, GsVec(0.0f, -2.5f, 1.0f));

	////buildings
	//p = new SnPrimitive(GsPrimitive::Box, 1.0f, 6.0f, 3.0);
	//p->prim().material.diffuse = GsColor::lightblue;
	//add_model(p, GsVec(-7.0f, 2.0f, 0));

	//back of basketball court
	p = new SnPrimitive(GsPrimitive::Box, 1.0f, 4.0f, 0.2f);
	p->prim().material.diffuse = GsColor::black;
	add_model(p, GsVec(0, 2.0f, -15.0f));

	//top of basketball court
	p = new SnPrimitive(GsPrimitive::Box, 3.0f, 3.0f, 0.5f);
	p->prim().material.diffuse = GsColor::white;
	add_model(p, GsVec(0, 8.0f, -15.0f));

	//2nd basketball court 
	p = new SnPrimitive(GsPrimitive::Box, 1.0f, 4.0f, 0.2f);
	p->prim().material.diffuse = GsColor::black;
	add_model(p, GsVec(0, 2.0f, 18.0f));


	//top of basketball court
	p = new SnPrimitive(GsPrimitive::Box, 3.0f, 3.0f, 0.5f);
	p->prim().material.diffuse = GsColor::white;
	add_model(p, GsVec(0, 8.0f, 18.0f));

	//basket
	p = new SnPrimitive(GsPrimitive::Cylinder, 2.0f, 2.0f, 0.2f);
	p->prim().material.diffuse = GsColor::red;
	add_model(p, GsVec(0.0f, 8.0f, 15.5f));

	p = new SnPrimitive(GsPrimitive::Cylinder, 2.0f, 2.0f, 0.2f);
	p->prim().material.diffuse = GsColor::red;
	add_model(p, GsVec(0.0f, 8.0f, -12.5f));

	SnModel* myscene = new SnModel(mymodel);
	SnModel* sn = new SnModel;

	GsModel& m = *myscene->model();


	//Create a "material group"
	GsModel::Group& g = *m.G.push();
	g.fi = 0;
	g.fn = m.F.size();
	g.dmap = new GsModel::Texture;
	//if (control == 1)
		g.dmap->fname.set("../src/basketball.JPG");

	//if (control == 2)
		//g.dmap->fname.set("../src/lion.JPG");

	//Make the number of materials matches the number of groups
	//if (control == 3)
		//g.dmap->fname.set("../src/goat.JPG");

	m.M.push().init();

	m.set_mode(GsModel::Smooth, GsModel::PerGroupMtl);
	m.textured = true;

	rootg()->add(myscene);
	//rootg()->add(Line);
	if (norvec) {
		rootg()->add(Line);
	}
}
void MyViewer::show_normals(bool view)
{
	// Note that primitives are only converted to meshes in GsModel
	// at the first draw call.
	GsArray<GsVec> fn;
	SnGroup* r = (SnGroup*)root();
	for (int k = 0; k < r->size(); k++)
	{
		SnManipulator* manip = r->get<SnManipulator>(k);
		SnShape* s = manip->child<SnGroup>()->get<SnShape>(0);
		SnLines* l = manip->child<SnGroup>()->get<SnLines>(1);
		if (!view) { l->visible(false); continue; }
		l->visible(true);
		if (!l->empty()) continue; // build only once
		l->init();
		if (s->instance_name() == SnPrimitive::class_name)
		{
			GsModel& m = *((SnModel*)s)->model();
			m.get_normals_per_face(fn);
			const GsVec* n = fn.pt();
			float f = 0.33f;
			for (int i = 0; i < m.F.size(); i++)
			{
				const GsVec& a = m.V[m.F[i].a]; l->push(a, a + (*n++) * f);
				const GsVec& b = m.V[m.F[i].b]; l->push(b, b + (*n++) * f);
				const GsVec& c = m.V[m.F[i].c]; l->push(c, c + (*n++) * f);
			}
		}
	}
}


void MyViewer::run_animation(){
	//int a, b, c;
	//double theta = GS_2PI / 100;
	if (_animating) return; // avoid recursive calls
	_animating = true;

	int ind = gs_random(0, rootg()->size() - 1); // pick one child
	SnManipulator* manip = rootg()->get<SnManipulator>(ind); // access one of the manipulators
	GsMat m = manip->mat();


	double frdt = 1.0/30.0; // delta time to reach given number of frames per second
	double v = 4; // target velocity is 1 unit per second
	double t=0, lt=0, t0=gs_time();
	do // run for a while:
	{	while ( t-lt<frdt ) { ws_check(); t=gs_time()-t0; } // wait until it is time for next frame
		double yinc = (t-lt)*v;
		if ( t>2 ) yinc=-yinc; // after 2 secs: go down
		lt = t;
		m.e24 += (float)yinc;
	if ( m.e24<0 ) m.e24=0; // make sure it does not go below 0
	manip->initial_mat ( m );
	render(); // notify it needs redraw
	ws_check(); // redraw now
	}	while ( m.e24>0 );
	_animating = false;

}
int MyViewer::handle_keyboard(const GsEvent& e) {
	int ret = WsViewer::handle_keyboard(e); // 1st let system check events
	if (ret) return ret;

	switch (e.key)
	{
	case GsEvent::KeyEsc: gs_exit(); return 1;
	case 'n': { bool b = !_nbut->value(); _nbut->value(b); show_normals(b); return 1; }
			//default: gsout << "Key pressed: " << e.key << gsnl;

	case 'a': {
		GsMat OriginMat;
		OriginMat.translation(0, 0, 0);//puttin it to origin
		GsMat rotation;//rotation matrix
		righthand +=10* ((float)GS_2PI / 360);//angle of rotation
		//gsout << righthand ;
		rotation.rotx(righthand);//doing rotation on righthand
		GsMat currentMatrix = right_hand->mat();//get reference manipulator matrix
		GsVec points = { currentMatrix.e14,(currentMatrix.e24) - 0.005f,currentMatrix.e34 - 0.005f };
		//GsVec points = { currentMatrix.e14,(currentMatrix.e24),currentMatrix.e34 };
		//GsMat test;
		//test.translation(-points);
		GsMat NewTranslation;
		NewTranslation.translation(points);
		GsMat FinalTransform = NewTranslation * rotation * OriginMat;
		//GsMat FinalTransform = NewTranslation * rotation *test* OriginMat;
		right_hand->initial_mat(FinalTransform);//doing transformation on hand
		render();
		return 1;
	}
	case 'b': {
		GsMat OriginMat;
		OriginMat.translation(0, 0, 0);//putting it to origin
		GsMat rotation;//rotation matrix
		righthand -= 10*((float)GS_2PI / 360);//angle of rotation
		rotation.rotx(righthand);//doing rotation on righthand
		GsMat currentMatrix = right_hand->mat();//get reference manipulator matrix
		GsVec points = { currentMatrix.e14,(currentMatrix.e24)
			+ 0.001f,currentMatrix.e34 + 0.001f };
		GsMat NewTranslation;
		NewTranslation.translation(points);
		//NewTranslation.translation(points);
		GsMat FinalTransform = NewTranslation * rotation * OriginMat;
		right_hand->initial_mat(FinalTransform);//doing transformation on hand
		render();
		return 1;
	}
	case 'c': {
		GsMat OriginMat;
		OriginMat.translation(0, 0, 0);
		GsMat rotation;//rotation matrix
		lefthand += ((float)GS_2PI / 360);//angle of rotation
		rotation.rotx(lefthand);
		GsMat currentMatrix = left_hand->mat();
		GsVec points = { currentMatrix.e14,(currentMatrix.e24) - 0.01f,currentMatrix.e34 - 0.01f };
		GsMat NewTranslation;
		NewTranslation.translation(points);
		GsMat FinalTransform = NewTranslation * rotation * OriginMat;
		left_hand->initial_mat(FinalTransform);
		render();
		return 1;

	}
	case 'd': {
		GsMat OriginMat;
		OriginMat.translation(0, 0, 0);
		GsMat rotation;//rotation matrix
		lefthand -= ((float)GS_2PI / 360);//angle of rotation
		rotation.rotx(lefthand);
		GsMat currentMatrix = left_hand->mat();
		GsVec points = { currentMatrix.e14,(currentMatrix.e24)
			+ 0.001f,currentMatrix.e34 + 0.001f };
		GsMat NewTranslation;
		NewTranslation.translation(points);
		GsMat FinalTransform = NewTranslation * rotation * OriginMat;
		left_hand->initial_mat(FinalTransform);
		render();
		return 1;

	}
	case 'e': {
		GsMat OriginMat;
		OriginMat.translation(0, 0, 0);
		GsMat rotation;//rotation matrix
		leftleg += ((float)GS_2PI / 360);//angle of rotation
		rotation.rotx(leftleg);
		GsMat currentMatrix = left_leg->mat();
		GsVec points = { currentMatrix.e14,(currentMatrix.e24) - 0.001f,currentMatrix.e34 - 0.001f };
		GsMat NewTranslation;
		NewTranslation.translation(points);
		GsMat FinalTransform = NewTranslation * rotation * OriginMat;
		left_leg->initial_mat(FinalTransform);
		render();
		return 1;
	}
	case 'f': {
		GsMat OriginMat;
		OriginMat.translation(0, 0, 0);
		GsMat rotation;//rotation matrix
		leftleg -= ((float)GS_2PI / 360);//angle of rotation
		rotation.rotx(leftleg);
		GsMat currentMatrix = left_leg->mat();
		GsVec points = { currentMatrix.e14,(currentMatrix.e24) - 0.001f,currentMatrix.e34 - 0.001f };
		GsMat NewTranslation;
		NewTranslation.translation(points);
		GsMat FinalTransform = NewTranslation * rotation * OriginMat;
		left_leg->initial_mat(FinalTransform);
		render();
		return 1;
	}
	case 'g': {
		GsMat OriginMat;
		OriginMat.translation(0, 0, 0);
		GsMat rotation;//rotation matrix
		rightleg += 10*((float)GS_2PI / 360);//angle of rotation
		rotation.rotx(rightleg);
		GsMat currentMatrix = right_leg->mat();
		GsVec points = { currentMatrix.e14,(currentMatrix.e24) - 0.001f,currentMatrix.e34 - 0.001f };
		GsMat NewTranslation;
		NewTranslation.translation(points);
		GsMat FinalTransform = NewTranslation * rotation * OriginMat;
		right_leg->initial_mat(FinalTransform);
		render();
		return 1;
	}
	case 'h': {
		GsMat OriginMat;
		OriginMat.translation(0, 0, 0);
		GsMat rotation;//rotation matrix
		rightleg -= ((float)GS_2PI / 360);//angle of rotation
		rotation.rotx(rightleg);
		GsMat currentMatrix = right_leg->mat();
		GsVec points = { currentMatrix.e14,(currentMatrix.e24) + 0.001f,currentMatrix.e34 + 0.001f };
		GsMat NewTranslation;
		NewTranslation.translation(points);
		GsMat FinalTransform = NewTranslation * rotation * OriginMat;
		right_leg->initial_mat(FinalTransform);
		render();
		return 1;
	}
	case 'i': {
		GsMat OriginMat;
		OriginMat.translation(0, 0, 0);
		GsMat rotation;//rotation matrix
		righthand += ((float)GS_2PI / 360);//angle of rotation
		rotation.rotz(righthand);
		GsMat currentMatrix = right_hand->mat();
		GsVec points = { currentMatrix.e14,(currentMatrix.e24) - 0.001f,currentMatrix.e34 - 0.001f };
		GsMat NewTranslation;
		NewTranslation.translation(points);
		GsMat FinalTransform = NewTranslation * rotation * OriginMat;
		right_hand->initial_mat(FinalTransform);
		render();
		return 1;

	}
	case 'j': {
		GsMat OriginMat;
		OriginMat.translation(0, 0, 0);
		GsMat rotation;//rotation matrix
		righthand -= ((float)GS_2PI / 360);//angle of rotation
		rotation.rotz(righthand);
		GsMat currentMatrix = right_hand->mat();
		GsVec points = { currentMatrix.e14,(currentMatrix.e24) + 0.001f,currentMatrix.e34 + 0.001f };
		GsMat NewTranslation;
		NewTranslation.translation(points);
		GsMat FinalTransform = NewTranslation * rotation * OriginMat;
		right_hand->initial_mat(FinalTransform);
		render();
		return 1;

	}
			//global movement
			//left arrow
	case 65361: {
		persontranslation = h_head->mat();//mat is manipulator matrix
		xposition = 0.1f;
		persontranslation.e14 -= xposition;
		h_head->initial_mat(persontranslation);
		render();
		return 1;

	}
			  //right arrow
	case 65363: {
		persontranslation = h_head->mat();
		xposition = 0.1f;
		persontranslation.e14 += xposition;
		h_head->initial_mat(persontranslation);
		render();
		return 1;
	}
			  //up
	case 65362: {
		persontranslation = h_head->mat();
		yposition = 0.1f;
		persontranslation.e24 += yposition;
		h_head->initial_mat(persontranslation);
		render();
		return 1;
	}
			  //down
	case 65364: {
		persontranslation = h_head->mat();
		yposition = 0.1f;
		persontranslation.e24 -= yposition;
		h_head->initial_mat(persontranslation);
		render();
		return 1;
	}
			  //delete later
	case ' ': {
		double lt, t0 = gs_time();
		if (control == false) {
			do {
				lt = gs_time() - t0;
				camera().eye.x += 0.01f;//moves right in x direction
				//camera().center.x += 0.009f;

				camera().eye.y += 0.01f;//moves right in y direction
				//camera().center.y += 0.009f;

				camera().eye.z += 0.01f;//moves right in z direction
				//camera().center.z += 0.009f;

				render();
				ws_check();
				//message().setf(“local time=%f”, lt);
			} while (lt < 3.0f);
			control = true;
		}
		else {
			double lt, t0 = gs_time();
			do {
				lt = gs_time() - t0;
				camera().eye.z -= 0.05f;//moves right in x direction
				//camera().center.x += 0.009f;

				//camera().eye.y += 0.01f;//moves right in y direction
				//camera().center.y += 0.009f;

				//camera().eye.z += 0.01f;//moves right in z direction
				//camera().center.z += 0.009f;

				render();
				ws_check();
				//message().setf(“local time=%f”, lt);
			} while (lt < 3.0f);

		}
		break;
		
		}
	}
	return 0;
}

			//default: gsout << "Key pressed: " << e.key << gsnl;


	




			int MyViewer::uievent(int e)
			{
				switch (e)
				{
				case EvNormals: show_normals(_nbut->value()); return 1;
				case EvAnimate: run_animation(); return 1;
				case EvExit: gs_exit();
				}
				return WsViewer::uievent(e);
			}

	
