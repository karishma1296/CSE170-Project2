
//comment
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

//person manip
SnManipulator* left_leg = new SnManipulator;
SnManipulator* right_leg = new SnManipulator;
SnManipulator* right_hand = new SnManipulator;
SnManipulator* left_hand = new SnManipulator;
SnManipulator* h_head = new SnManipulator;
SnManipulator* h_neck = new SnManipulator;
SnManipulator* h_hips = new SnManipulator;
SnManipulator* h_chest = new SnManipulator;

//car manip
SnManipulator* top = new SnManipulator;
SnManipulator* bottom = new SnManipulator;
SnManipulator* frontwheel1 = new SnManipulator;
SnManipulator* frontwheel2 = new SnManipulator;
SnManipulator* backwheel1 = new SnManipulator;
SnManipulator* backwheel2 = new SnManipulator;



SnManipulator* persontranslation = new SnManipulator;
float yposition = 0.0f;
float xposition = 0.0f;

static float radius = 0.5f;
static float R = 1.0f;
static float height = 0.3f;
static float width = 0.3f;
static int n = 30;


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
	
	SnGroup* person = new SnGroup;//pointer person to SnGroup
	//person->separator(true);
	//his head
	SnPrimitive* hhead = new SnPrimitive(GsPrimitive::Sphere, 1.3f);
	hhead->prim().material.diffuse = GsColor::lightgray;
	t.setrans(0, 6.4f, 65);
	
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


	//right leg
	SnPrimitive* rightleg = new SnPrimitive(GsPrimitive::Capsule, 0.2f, 0.2f, 1.0f);
	rightleg->prim().material.diffuse = GsColor::darkgreen;
	t.setrans(0.5f, -1.0f, 0.0f);

	SnGroup* _rightleg = new SnGroup;
	_rightleg->add(rightleg);
	right_leg->child(_rightleg);
	_hhips->add(right_leg);
	right_leg->initial_mat(t);

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


	//floor
	p = new SnPrimitive(GsPrimitive::Box, 70.0f, 0.01f, 70.0f);
	p->prim().material.diffuse = GsColor::lightgray;
	add_model(p, GsVec(0.0f, -0.3f, 1.0f));

	buildcar();
	
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

void MyViewer::buildcar(){
	GsModel* mymodel = new GsModel;
	SnGroup* pos_sng = new SnGroup;

	//top part of car
	SnPrimitive* tcar_sn = new SnPrimitive(GsPrimitive::Box, 3.6f, 2.1f, 4.45f);
	tcar_sn->prim().material.diffuse = GsColor::magenta;
	transm.setrans(-0.1f, 4.5f, 55.0f);

	SnGroup* topgroup = new SnGroup;
	topgroup->add(tcar_sn);
	top->child(topgroup);
	pos_sng->add(top);
	top->initial_mat(transm);
	rootg()->add(top);

	//body of car
	SnPrimitive* bcar_sn = new SnPrimitive(GsPrimitive::Box, 6.0f, 1.5f, 4.5f);
	bcar_sn->prim().material.diffuse = GsColor::blue;
	transm.setrans(0.0f, -2.0f, 0.0f);

	SnGroup* bottomsng = new SnGroup;
	bottomsng->add(bcar_sn);
	bottom->child(bottomsng);
	topgroup->add(bottom);
	bottom->initial_mat(transm);

	//torus creation 
	mymodel = new GsModel;
	double centerp = 0;
	double centert = 0;
	double phi = 0;
	double theta = 0;
	double delta = 0;
	double x, y, z = 0;
	double x_2, y_2, z_2 = 0.0;
	double x_3, y_3, z_3 = 0.0;
	double x_4, y_4, z_4 = 0.0;

	SnLines* line = new SnLines;
	line->init();
	GsModel& torus = *mymodel;

	SnModel* frontwheel1_sn = new SnModel(&torus);

	line->color(GsColor::red);
	//display faces

	int i0 = 0;		//face index
	line->init();
	int faceIndex = 0;
	int vIndex = 0;
	for (int i = 0; i <= n; i++) {
		phi += (GS_2PI / n);
		for (int j = 0; j <= n; j++) {
			theta += (GS_2PI / n);
			delta = (GS_2PI / n);

			//first point (theta, phi) 0 
			x = (R + radius * cos(theta)) * cos(phi);
			y = ((R + radius * cos(theta)) * sin(phi));
			z = (radius * sin(theta));
			//GS_2PI;

			//second point (theta + delta_theta, phi) 1 
			x_2 = (R + radius * cos(theta + delta)) * cos(phi);
			y_2 = ((R + radius * cos(theta + delta)) * sin(phi));
			z_2 = (radius * sin(theta + delta));

			//third point (theta + delta_theta, phi+delta_phi) 2
			x_3 = (R + radius * cos(theta + delta)) * cos(phi + delta);
			y_3 = ((R + radius * cos(theta + delta)) * sin(phi + delta));
			z_3 = (radius * sin(theta + delta));

			//fourth point (theta, phi+delta_phi) 3
			x_4 = (R + radius * cos(theta)) * cos(phi + delta);
			y_4 = ((R + radius * cos(theta)) * sin(phi + delta));
			z_4 = (radius * sin(theta));

			a = GsVec(x, y, z);
			b = GsVec(x_2, y_2, z_2);
			c = GsVec(x_3, y_3, z_3);
			d = GsVec(x_4, y_4, z_4);

			mymodel->V.push(d);			//0
			mymodel->V.push(c);			//1
			mymodel->V.push(b);			//2
			mymodel->V.push(d);
			mymodel->V.push(b);
			mymodel->V.push(a);			//3

			mymodel->F.push() = GsModel::Face(i0, i0 + 1, i0 + 2);			//d,c,b
			mymodel->F.push() = GsModel::Face(i0 + 3, i0 + 4, i0 + 5);			//d,b,a
			i0 += 6;

			float one = float(R * cos(phi)), two = float(R * sin(phi)), three = 0;
			float two_1 = float(R * cos(phi + delta)), two_2 = float(R * sin((phi + delta))), two_3 = 0;
			GsPnt centersmooth1 = GsVec(one, two, three);
			GsPnt centersmooth2 = GsVec(two_1, two_2, two_3);

			GsPnt n_a = a - centersmooth1;
			GsPnt n_b = b - centersmooth1;
			GsPnt n_c = c - centersmooth2;
			GsPnt n_d = d - centersmooth2;

			torus.N.push(n_d);
			torus.N.push(n_c);
			torus.N.push(n_b);

			torus.N.push(n_d);
			torus.N.push(n_b);
			torus.N.push(n_a);

			GsPnt n_smooth1 = cross(a - b, c - d);
			GsPnt n_smooth2 = cross(a - c, c - b);

		}
	}

	GsModel::Group& g = *torus.G.push();
	//fi is the intial face 
	//fn is the number of faces
	g.fi = 0;
	g.fn = torus.F.size();
	g.dmap = new GsModel::Texture;

	//g.dmap->fname.set("grass_texture.jpg");
	torus.M.push().init();					//M - list of materials 
	torus.M.top() = GsMaterial::DefaultSpecular;
	int nv = torus.V.size();				// V - list of vertex coordinates 
	torus.T.size(nv);						//T - list of texture coordinates

	phi = 0.0;
	theta = 0.0;
	int l = 0;

	for (int i = 0; i <= n; i++) {
		phi += (GS_2PI / n);
		double delta_phi = (GS_2PI / n);
		for (int j = 0; j <= n; j++) {
			double delta_theta = (GS_2PI / n);
			theta += (GS_2PI / n);
			torus.T[l].set((theta / GS_2PI), (phi + delta_phi) / GS_2PI);						//d
			torus.T[l + 1].set((theta + delta_theta) / GS_2PI, (phi + delta_phi) / GS_2PI);	//c
			torus.T[l + 2].set((theta + delta_theta) / GS_2PI, phi / GS_2PI);				//b
			torus.T[l + 3].set(theta / GS_2PI, (phi + delta_phi) / GS_2PI);					//d
			torus.T[l + 4].set((theta + delta_theta) / GS_2PI, phi / GS_2PI);				//b
			torus.T[l + 5].set(theta / GS_2PI, phi / GS_2PI);								//a
			l += 6;

		}
	}
	torus.textured = false;
	torus.set_mode(GsModel::Smooth, GsModel::PerGroupMtl);
	//rootg()->add(myscene);

	transm.setrans(5.0f, -1.0f, 4.5f);
	SnGroup* fwheelgroup = new SnGroup;
	fwheelgroup->add(frontwheel1_sn);
	frontwheel1->child(fwheelgroup);
	bottomsng->add(frontwheel1);
	frontwheel1->initial_mat(transm);

	//front wheels 
	GsModel& torus2 = *mymodel;
	SnModel* frontwheel2_sn = new SnModel(&torus2);
	transm.setrans(5.0f, -1.0f, -4.5f);

	SnGroup* fwheelgroup2 = new SnGroup;
	fwheelgroup2->add(frontwheel2_sn);
	frontwheel2->child(fwheelgroup2);
	bottomsng->add(frontwheel2);
	frontwheel2->initial_mat(transm);

	//back wheels 
	GsModel& torus3 = *mymodel;
	SnModel* backwheel1_sn = new SnModel(&torus3);
	transm.setrans(-5.0f, -1.0f, 4.5f);

	SnGroup* backwheelgroup1 = new SnGroup;
	backwheelgroup1->add(backwheel1_sn);
	backwheel1->child(backwheelgroup1);
	bottomsng->add(backwheel1);
	backwheel1->initial_mat(transm);

	GsModel& torus4 = *mymodel;
	SnModel* backwheel2_sn = new SnModel(&torus4);
	transm.setrans(-5.0f, -1.0f, -4.5f);

	SnGroup* backwheelgroup2 = new SnGroup;
	backwheelgroup2->add(backwheel2_sn);
	backwheel2->child(backwheelgroup2);
	bottomsng->add(backwheel2);
	backwheel2->initial_mat(transm);

	
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

	
