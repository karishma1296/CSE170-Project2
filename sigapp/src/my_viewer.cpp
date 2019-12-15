
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
GsModel* mymodel = new GsModel;

//person manip
SnManipulator* left_leg = new SnManipulator;
SnManipulator* right_leg = new SnManipulator;
SnManipulator* right_hand = new SnManipulator;
SnManipulator* left_hand = new SnManipulator;
SnManipulator* h_head = new SnManipulator;
SnManipulator* h_neck = new SnManipulator;
SnManipulator* h_hips = new SnManipulator;
SnManipulator* h_chest = new SnManipulator;

//row_numcar
//first row of cars
SnManipulator* top1_1 = new SnManipulator;
SnManipulator* bottom1_1 = new SnManipulator;
SnManipulator* frontlwheel1_1 = new SnManipulator;
SnManipulator* frontrwheel1_1 = new SnManipulator;
SnManipulator* backlwheel1_1 = new SnManipulator;
SnManipulator* backrwheel1_1 = new SnManipulator;

SnManipulator* top1_2 = new SnManipulator;
SnManipulator* bottom1_2 = new SnManipulator;
SnManipulator* frontlwheel1_2 = new SnManipulator;
SnManipulator* frontrwheel1_2 = new SnManipulator;
SnManipulator* backlwheel1_2= new SnManipulator;
SnManipulator* backrwheel1_2 = new SnManipulator;

SnManipulator* top1_3 = new SnManipulator;
SnManipulator* bottom1_3 = new SnManipulator;
SnManipulator* frontlwheel1_3 = new SnManipulator;
SnManipulator* frontrwheel1_3 = new SnManipulator;
SnManipulator* backlwheel1_3 = new SnManipulator;
SnManipulator* backrwheel1_3 = new SnManipulator;

SnManipulator* top1_4 = new SnManipulator;
SnManipulator* bottom1_4 = new SnManipulator;
SnManipulator* frontlwheel1_4 = new SnManipulator;
SnManipulator* frontrwheel1_4 = new SnManipulator;
SnManipulator* backlwheel1_4 = new SnManipulator;
SnManipulator* backrwheel1_4 = new SnManipulator;

//second row 
SnManipulator* top2_1 = new SnManipulator;
SnManipulator* bottom2_1 = new SnManipulator;
SnManipulator* frontlwheel2_1 = new SnManipulator;
SnManipulator* frontrwheel2_1 = new SnManipulator;
SnManipulator* backlwheel2_1 = new SnManipulator;
SnManipulator* backrwheel2_1 = new SnManipulator;

SnManipulator* top2_2 = new SnManipulator;
SnManipulator* bottom2_2 = new SnManipulator;
SnManipulator* frontlwheel2_2 = new SnManipulator;
SnManipulator* frontrwheel2_2 = new SnManipulator;
SnManipulator* backlwheel2_2 = new SnManipulator;
SnManipulator* backrwheel2_2 = new SnManipulator;

SnManipulator* top2_3 = new SnManipulator;
SnManipulator* bottom2_3 = new SnManipulator;
SnManipulator* frontlwheel2_3 = new SnManipulator;
SnManipulator* frontrwheel2_3 = new SnManipulator;
SnManipulator* backlwheel2_3 = new SnManipulator;
SnManipulator* backrwheel2_3 = new SnManipulator;

SnManipulator* top2_4 = new SnManipulator;
SnManipulator* bottom2_4 = new SnManipulator;
SnManipulator* frontlwheel2_4 = new SnManipulator;
SnManipulator* frontrwheel2_4 = new SnManipulator;
SnManipulator* backlwheel2_4 = new SnManipulator;
SnManipulator* backrwheel2_4 = new SnManipulator;

//third row
SnManipulator* top3_1 = new SnManipulator;
SnManipulator* bottom3_1 = new SnManipulator;
SnManipulator* frontlwheel3_1 = new SnManipulator;
SnManipulator* frontrwheel3_1 = new SnManipulator;
SnManipulator* backlwheel3_1 = new SnManipulator;
SnManipulator* backrwheel3_1 = new SnManipulator;

SnManipulator* top3_2 = new SnManipulator;
SnManipulator* bottom3_2 = new SnManipulator;
SnManipulator* frontlwheel3_2 = new SnManipulator;
SnManipulator* frontrwheel3_2 = new SnManipulator;
SnManipulator* backlwheel3_2 = new SnManipulator;
SnManipulator* backrwheel3_2 = new SnManipulator;

SnManipulator* top3_3 = new SnManipulator;
SnManipulator* bottom3_3 = new SnManipulator;
SnManipulator* frontlwheel3_3 = new SnManipulator;
SnManipulator* frontrwheel3_3 = new SnManipulator;
SnManipulator* backlwheel3_3 = new SnManipulator;
SnManipulator* backrwheel3_3 = new SnManipulator;

SnManipulator* top3_4 = new SnManipulator;
SnManipulator* bottom3_4 = new SnManipulator;
SnManipulator* frontlwheel3_4 = new SnManipulator;
SnManipulator* frontrwheel3_4 = new SnManipulator;
SnManipulator* backlwheel3_4 = new SnManipulator;
SnManipulator* backrwheel3_4 = new SnManipulator;


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
	t.setrans(0, 6.4f, 60);
	
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
	p = new SnPrimitive(GsPrimitive::Box, 65.0f, 0.01f, 65.0f);
	p->prim().material.diffuse = GsColor::lightgray;
	add_model(p, GsVec(0.0f, -0.3f, 1.0f));

	buildfirstrow();
	buildsecondrow();
	buildthirdrow();
	buildfourthrow();
	buildfifthrow();
	buildsixthrow();
	
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

void MyViewer::buildfirstrow(){
	
	//SnGroup* firstrow = new SnGroup;
	//top part of car
	SnPrimitive* tcar_sn1_1 = new SnPrimitive(GsPrimitive::Box, 3.6f, 2.1f, 4.45f);
	tcar_sn1_1->prim().material.diffuse = GsColor::magenta;
	transm.setrans(-55.0f, 4.5f, 50.0f);

	SnGroup* topgroup1_1 = new SnGroup;
	topgroup1_1->add(tcar_sn1_1);
	top1_1->child(topgroup1_1);
	top1_1->initial_mat(transm);
	rootg()->add(top1_1);

	//body of car
	SnPrimitive* bcar_sn1_1 = new SnPrimitive(GsPrimitive::Box, 6.0f, 1.5f, 4.5f);
	bcar_sn1_1->prim().material.diffuse = GsColor::blue;
	transm.setrans(0.0f, -2.0f, 0.0f);

	SnGroup* bottomsng1_1 = new SnGroup;
	bottomsng1_1->add(bcar_sn1_1);
	bottom1_1->child(bottomsng1_1);
	topgroup1_1->add(bottom1_1);
	bottom1_1->initial_mat(transm);

	//torus creation 
	mymodel = new GsModel;
	double centert = 0;
	double centerp = 0;
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

	//front wheels
	transm.setrans(5.0f, -1.0f, 4.5f);
	SnGroup* fwheellgroup1_1 = new SnGroup;
	fwheellgroup1_1->add(frontwheel1_sn);
	frontlwheel1_1->child(fwheellgroup1_1);
	bottomsng1_1->add(frontlwheel1_1);
	frontlwheel1_1->initial_mat(transm);
	GsModel& torus2 = *mymodel;
	SnModel* frontrwheel_sn1_1 = new SnModel(&torus2);
	transm.setrans(5.0f, -1.0f, -4.5f);
	SnGroup* frwheelgroup1_1 = new SnGroup;
	frwheelgroup1_1->add(frontrwheel_sn1_1);
	frontrwheel1_1->child(frwheelgroup1_1);
	bottomsng1_1->add(frontrwheel1_1);
	frontrwheel1_1->initial_mat(transm);
	
	//back wheels 
	GsModel& torus3 = *mymodel;
	SnModel* backlwheel_sn1_1 = new SnModel(&torus3);
	transm.setrans(-5.0f, -1.0f, 4.5f);
	SnGroup* backlwheelgroup1_1 = new SnGroup;
	backlwheelgroup1_1->add(backlwheel_sn1_1);
	backlwheel1_1->child(backlwheelgroup1_1);
	bottomsng1_1->add(backlwheel1_1);
	backlwheel1_1->initial_mat(transm);
	GsModel& torus4 = *mymodel;
	SnModel* backrwheel_sn1_1 = new SnModel(&torus4);
	transm.setrans(-5.0f, -1.0f, -4.5f);
	SnGroup* backrwheelgroup1_1 = new SnGroup;
	backrwheelgroup1_1->add(backrwheel_sn1_1);
	backrwheel1_1->child(backrwheelgroup1_1);
	bottomsng1_1->add(backrwheel1_1);
	backrwheel1_1->initial_mat(transm);

	//second car 
	//top part of car
	SnPrimitive* tcar_sn1_2 = new SnPrimitive(GsPrimitive::Box, 3.6f, 2.1f, 4.45f);
	tcar_sn1_2->prim().material.diffuse = GsColor::magenta;
	transm.setrans(35.0f, 0.0f, 0.0f);
	SnGroup* topgroup1_2 = new SnGroup;
	topgroup1_2->add(tcar_sn1_2);
	top1_2->child(topgroup1_2);
	top1_2->initial_mat(transm);

	//body of car
	SnPrimitive* bcar_sn1_2 = new SnPrimitive(GsPrimitive::Box, 6.0f, 1.5f, 4.5f);
	bcar_sn1_2->prim().material.diffuse = GsColor::blue;
	transm.setrans(0.0f, -2.0f, 0.0f);
	SnGroup* bottomsng1_2 = new SnGroup;
	bottomsng1_2->add(bcar_sn1_2);
	bottom1_2->child(bottomsng1_2);
	topgroup1_2->add(bottom1_2);
	bottom1_2->initial_mat(transm);

	//front wheels - 5,6,7,8
	GsModel& torus5 = *mymodel;
	SnModel* frontlwheel_sn1_2 = new SnModel(&torus5);
	transm.setrans(5.0f, -1.0f, 4.5f);
	SnGroup* flwheelgroup1_2 = new SnGroup;
	flwheelgroup1_2->add(frontlwheel_sn1_2);
	frontlwheel1_2->child(flwheelgroup1_2);
	bottomsng1_2->add(frontlwheel1_2);
	frontlwheel1_2->initial_mat(transm);
	GsModel& torus6 = *mymodel;
	SnModel* frontrwheel_sn1_2 = new SnModel(&torus6);
	transm.setrans(5.0f, -1.0f, -4.5f);
	SnGroup* frwheelgroup1_2 = new SnGroup;
	frwheelgroup1_2->add(frontrwheel_sn1_2);
	frontrwheel1_2->child(frwheelgroup1_2);
	bottomsng1_2->add(frontrwheel1_2);
	frontrwheel1_2->initial_mat(transm);

	//back wheels 
	GsModel& torus7 = *mymodel;
	SnModel* backlwheel_sn1_2 = new SnModel(&torus7);
	transm.setrans(-5.0f, -1.0f, 4.5f);
	SnGroup* backwheelgroup1_1 = new SnGroup;
	backwheelgroup1_1->add(backlwheel_sn1_2);
	backlwheel1_2->child(backwheelgroup1_1);
	bottomsng1_2->add(backlwheel1_2);
	backlwheel1_2->initial_mat(transm);
	GsModel& torus8 = *mymodel;
	SnModel* backrwheel_sn1_2 = new SnModel(&torus8);
	transm.setrans(-5.0f, -1.0f, -4.5f);
	SnGroup* backrwheelgroup1_2 = new SnGroup;
	backrwheelgroup1_2->add(backrwheel_sn1_2);
	backrwheel1_2->child(backrwheelgroup1_2);
	bottomsng1_2->add(backrwheel1_2);
	backrwheel1_2->initial_mat(transm);

	//third car 
	//top part of car
	SnPrimitive* tcar_sn1_3 = new SnPrimitive(GsPrimitive::Box, 3.6f, 2.1f, 4.45f);
	tcar_sn1_3->prim().material.diffuse = GsColor::magenta;
	transm.setrans(35.0f, 0.0f, 0.0f);
	SnGroup* topgroup1_3 = new SnGroup;
	topgroup1_3->add(tcar_sn1_3);
	top1_3->child(topgroup1_3);
	top1_3->initial_mat(transm);

	//body of car
	SnPrimitive* bcar_sn1_3 = new SnPrimitive(GsPrimitive::Box, 6.0f, 1.5f, 4.5f);
	bcar_sn1_3->prim().material.diffuse = GsColor::blue;
	transm.setrans(0.0f, -2.0f, 0.0f);
	SnGroup* bottomsng1_3 = new SnGroup;
	bottomsng1_3->add(bcar_sn1_3);
	bottom1_3->child(bottomsng1_3);
	topgroup1_3->add(bottom1_3);
	bottom1_3->initial_mat(transm);

	//front wheels - 9,10,11,12
	GsModel& torus9 = *mymodel;
	SnModel* frontlwheel_sn1_3 = new SnModel(&torus9);
	transm.setrans(5.0f, -1.0f, 4.5f);
	SnGroup* flwheelgroup1_3 = new SnGroup;
	flwheelgroup1_3->add(frontlwheel_sn1_3);
	frontlwheel1_3->child(flwheelgroup1_3);
	bottomsng1_3->add(frontlwheel1_3);
	frontlwheel1_3->initial_mat(transm);
	GsModel& torus10 = *mymodel;
	SnModel* frontrwheel_sn1_3 = new SnModel(&torus10);
	transm.setrans(5.0f, -1.0f, -4.5f);
	SnGroup* frwheelgroup1_3 = new SnGroup;
	frwheelgroup1_3->add(frontrwheel_sn1_3);
	frontrwheel1_3->child(frwheelgroup1_3);
	bottomsng1_3->add(frontrwheel1_3);
	frontrwheel1_3->initial_mat(transm);

	//back wheels 
	GsModel& torus11 = *mymodel;
	SnModel* backlwheel_sn1_3 = new SnModel(&torus11);
	transm.setrans(-5.0f, -1.0f, 4.5f);
	SnGroup* backlwheelgroup1_3 = new SnGroup;
	backlwheelgroup1_3->add(backlwheel_sn1_3);
	backlwheel1_3->child(backlwheelgroup1_3);
	bottomsng1_3->add(backlwheel1_3);
	backlwheel1_3->initial_mat(transm);
	GsModel& torus12 = *mymodel;
	SnModel* backrwheel_sn1_3 = new SnModel(&torus12);
	transm.setrans(-5.0f, -1.0f, -4.5f);
	SnGroup* backrwheelgroup1_3 = new SnGroup;
	backrwheelgroup1_3->add(backrwheel_sn1_3);
	backrwheel1_3->child(backrwheelgroup1_3);
	bottomsng1_3->add(backrwheel1_3);
	backrwheel1_3->initial_mat(transm);

	//fourth car 
	//top part of car
	SnPrimitive* tcar_sn1_4 = new SnPrimitive(GsPrimitive::Box, 3.6f, 2.1f, 4.45f);
	tcar_sn1_4->prim().material.diffuse = GsColor::magenta;
	transm.setrans(35.0f, 0.0f, 0.0f);
	SnGroup* topgroup1_4 = new SnGroup;
	topgroup1_4->add(tcar_sn1_4);
	top1_4->child(topgroup1_4);
	top1_4->initial_mat(transm);

	//body of car
	SnPrimitive* bcar_sn1_4 = new SnPrimitive(GsPrimitive::Box, 6.0f, 1.5f, 4.5f);
	bcar_sn1_4->prim().material.diffuse = GsColor::blue;
	transm.setrans(0.0f, -2.0f, 0.0f);
	SnGroup* bottomsng1_4 = new SnGroup;
	bottomsng1_4->add(bcar_sn1_4);
	bottom1_4->child(bottomsng1_4);
	topgroup1_4->add(bottom1_4);
	bottom1_4->initial_mat(transm);

	//front wheels - 13,14,15,16
	GsModel& torus13 = *mymodel;
	SnModel* frontlwheel_sn1_4 = new SnModel(&torus13);
	transm.setrans(5.0f, -1.0f, 4.5f);
	SnGroup* flwheelgroup1_4 = new SnGroup;
	flwheelgroup1_4->add(frontlwheel_sn1_4);
	frontlwheel1_4->child(flwheelgroup1_4);
	bottomsng1_4->add(frontlwheel1_4);
	frontlwheel1_4->initial_mat(transm);
	GsModel& torus14 = *mymodel;
	SnModel* frontrwheel_sn1_4 = new SnModel(&torus14);
	transm.setrans(5.0f, -1.0f, -4.5f);
	SnGroup* frwheelgroup1_4 = new SnGroup;
	frwheelgroup1_4->add(frontrwheel_sn1_4);
	frontrwheel1_4->child(frwheelgroup1_4);
	bottomsng1_4->add(frontrwheel1_4);
	frontrwheel1_4->initial_mat(transm);

	//back wheels 
	GsModel& torus15 = *mymodel;
	SnModel* backlwheel_sn1_4 = new SnModel(&torus15);
	transm.setrans(-5.0f, -1.0f, 4.5f);
	SnGroup* backlwheelgroup1_4 = new SnGroup;
	backlwheelgroup1_4->add(backlwheel_sn1_4);
	backlwheel1_4->child(backlwheelgroup1_4);
	bottomsng1_4->add(backlwheel1_4);
	backlwheel1_4->initial_mat(transm);
	GsModel& torus16 = *mymodel;
	SnModel* backrwheel_sn1_4 = new SnModel(&torus16);
	transm.setrans(-5.0f, -1.0f, -4.5f);
	SnGroup* backrwheelgroup1_4 = new SnGroup;
	backrwheelgroup1_4->add(backrwheel_sn1_4);
	backrwheel1_4->child(backrwheelgroup1_4);
	bottomsng1_4->add(backrwheel1_4);
	backrwheel1_4->initial_mat(transm);
	
	//car hierarchy of row 1 
	topgroup1_1->add(top1_2);
	topgroup1_2->add(top1_3);
	topgroup1_3->add(top1_4);
}

void MyViewer::buildsecondrow() {
	SnPrimitive* tcar_sn2_1 = new SnPrimitive(GsPrimitive::Box, 3.6f, 2.1f, 4.45f);
	tcar_sn2_1->prim().material.diffuse = GsColor::magenta;
	transm2.setrans(-55.0f, 4.5f, 35.0f);
	SnGroup* topgroup2_1 = new SnGroup;
	topgroup2_1->add(tcar_sn2_1);
	top2_1->child(topgroup2_1);
	top2_1->initial_mat(transm2);
	rootg()->add(top2_1);

	//body of car
	SnPrimitive* bcar_sn2_1 = new SnPrimitive(GsPrimitive::Box, 6.0f, 1.5f, 4.5f);
	bcar_sn2_1->prim().material.diffuse = GsColor::blue;
	transm2.setrans(0.0f, -2.0f, 0.0f);
	SnGroup* bottomsng2_1 = new SnGroup;
	bottomsng2_1->add(bcar_sn2_1);
	bottom2_1->child(bottomsng2_1);
	topgroup2_1->add(bottom2_1);
	bottom2_1->initial_mat(transm2);

	//front wheels - 17,18,19,20
	GsModel& torus17 = *mymodel;
	SnModel* frontlwheel_sn2_1 = new SnModel(&torus17);
	transm2.setrans(5.0f, -1.0f, 4.5f);
	SnGroup* flwheelgroup2_1 = new SnGroup;
	flwheelgroup2_1->add(frontlwheel_sn2_1);
	frontlwheel2_1->child(flwheelgroup2_1);
	bottomsng2_1->add(frontlwheel2_1);
	frontlwheel2_1->initial_mat(transm2);

	GsModel& torus18 = *mymodel;
	SnModel* frontrwheel_sn2_1 = new SnModel(&torus18);
	transm2.setrans(5.0f, -1.0f, -4.5f);
	SnGroup* frwheelgroup2_1 = new SnGroup;
	frwheelgroup2_1->add(frontrwheel_sn2_1);
	frontrwheel2_1->child(frwheelgroup2_1);
	bottomsng2_1->add(frontrwheel2_1);
	frontrwheel2_1->initial_mat(transm2);

	//back wheels 
	GsModel& torus19 = *mymodel;
	SnModel* backlwheel_sn2_1 = new SnModel(&torus19);
	transm2.setrans(-5.0f, -1.0f, 4.5f);
	SnGroup* backwheelgroup2_1 = new SnGroup;
	backwheelgroup2_1->add(backlwheel_sn2_1);
	backlwheel2_1->child(backwheelgroup2_1);
	bottomsng2_1->add(backlwheel2_1);
	backlwheel2_1->initial_mat(transm2);
	GsModel& torus20 = *mymodel;
	SnModel* backrwheel_sn2_1 = new SnModel(&torus20);
	transm2.setrans(-5.0f, -1.0f, -4.5f);
	SnGroup* backrwheelgroup2_1 = new SnGroup;
	backrwheelgroup2_1->add(backrwheel_sn2_1);
	backrwheel2_1->child(backwheelgroup2_1);
	bottomsng2_1->add(backrwheel2_1);
	backrwheel2_1->initial_mat(transm2);

	//second car 
	//top part of car
	SnPrimitive* tcar_sn2_2 = new SnPrimitive(GsPrimitive::Box, 3.6f, 2.1f, 4.45f);
	tcar_sn2_2->prim().material.diffuse = GsColor::magenta;
	transm2.setrans(35.0f, 0.0f, 0.0f);
	SnGroup* topgroup2_2 = new SnGroup;
	topgroup2_2->add(tcar_sn2_2);
	top2_2->child(topgroup2_2);
	top2_2->initial_mat(transm2);

	//body of car
	SnPrimitive* bcar_sn2_2 = new SnPrimitive(GsPrimitive::Box, 6.0f, 1.5f, 4.5f);
	bcar_sn2_2->prim().material.diffuse = GsColor::blue;
	transm2.setrans(0.0f, -2.0f, 0.0f);
	SnGroup* bottomsng2_2 = new SnGroup;
	bottomsng2_2->add(bcar_sn2_2);
	bottom2_2->child(bottomsng2_2);
	topgroup2_2->add(bottom2_2);
	bottom2_2->initial_mat(transm2);

	//front wheels - 21,22,23,24
	GsModel& torus21 = *mymodel;
	SnModel* frontlwheel_sn2_2 = new SnModel(&torus21);
	transm2.setrans(5.0f, -1.0f, 4.5f);
	SnGroup* flwheelgroup2_2 = new SnGroup;
	flwheelgroup2_2->add(frontlwheel_sn2_2);
	frontlwheel2_2->child(flwheelgroup2_2);
	bottomsng2_2->add(frontlwheel2_2);
	frontlwheel2_2->initial_mat(transm2);
	GsModel& torus22 = *mymodel;
	SnModel* frontrwheel_sn2_2 = new SnModel(&torus22);
	transm2.setrans(5.0f, -1.0f, -4.5f);
	SnGroup* frwheelgroup2_2 = new SnGroup;
	frwheelgroup2_2->add(frontrwheel_sn2_2);
	frontrwheel2_2->child(frwheelgroup2_2);
	bottomsng2_2->add(frontrwheel2_2);
	frontrwheel2_2->initial_mat(transm2);

	//back wheels 
	GsModel& torus23 = *mymodel;
	SnModel* backlwheel_sn2_2 = new SnModel(&torus23);
	transm2.setrans(-5.0f, -1.0f, 4.5f);
	SnGroup* backwheelgroup2_2 = new SnGroup;
	backwheelgroup2_2->add(backlwheel_sn2_2);
	backlwheel2_2->child(backwheelgroup2_2);
	bottomsng2_2->add(backlwheel2_2);
	backlwheel2_2->initial_mat(transm2);
	GsModel& torus24 = *mymodel;
	SnModel* backrwheel_sn2_2 = new SnModel(&torus24);
	transm2.setrans(-5.0f, -1.0f, -4.5f);
	SnGroup* backrwheelgroup2_2 = new SnGroup;
	backrwheelgroup2_2->add(backrwheel_sn2_2);
	backrwheel2_2->child(backrwheelgroup2_2);
	bottomsng2_2->add(backrwheel2_2);
	backrwheel2_2->initial_mat(transm2);

	//third car 
	//top part of car
	SnPrimitive* tcar_sn2_3 = new SnPrimitive(GsPrimitive::Box, 3.6f, 2.1f, 4.45f);
	tcar_sn2_3->prim().material.diffuse = GsColor::magenta;
	transm2.setrans(35.0f, 0.0f, 0.0f);
	SnGroup* topgroup2_3 = new SnGroup;
	topgroup2_3->add(tcar_sn2_3);
	top2_3->child(topgroup2_3);
	top2_3->initial_mat(transm2);

	//body of car
	SnPrimitive* bcar_sn2_3 = new SnPrimitive(GsPrimitive::Box, 6.0f, 1.5f, 4.5f);
	bcar_sn2_3->prim().material.diffuse = GsColor::blue;
	transm2.setrans(0.0f, -2.0f, 0.0f);
	SnGroup* bottomsng2_3 = new SnGroup;
	bottomsng2_3->add(bcar_sn2_3);
	bottom2_3->child(bottomsng2_3);
	topgroup2_3->add(bottom2_3);
	bottom2_3->initial_mat(transm2);

	//front wheels - 25,26,27,28
	GsModel& torus25 = *mymodel;
	SnModel* frontlwheel_sn2_3 = new SnModel(&torus25);
	transm2.setrans(5.0f, -1.0f, 4.5f);
	SnGroup* flwheelgroup2_3 = new SnGroup;
	flwheelgroup2_3->add(frontlwheel_sn2_3);
	frontlwheel2_3->child(flwheelgroup2_3);
	bottomsng2_3->add(frontlwheel2_3);
	frontlwheel2_3->initial_mat(transm2);
	GsModel& torus26 = *mymodel;
	SnModel* frontrwheel_sn2_3 = new SnModel(&torus26);
	transm2.setrans(5.0f, -1.0f, -4.5f);
	SnGroup* frwheelgroup2_3 = new SnGroup;
	frwheelgroup2_3->add(frontrwheel_sn2_3);
	frontrwheel2_3->child(frwheelgroup2_3);
	bottomsng2_3->add(frontrwheel2_3);
	frontrwheel2_3->initial_mat(transm2);

	//back wheels 
	GsModel& torus27 = *mymodel;
	SnModel* backlwheel_sn2_3 = new SnModel(&torus27);
	transm2.setrans(-5.0f, -1.0f, 4.5f);
	SnGroup* backwheelgroup2_3 = new SnGroup;
	backwheelgroup2_3->add(backlwheel_sn2_3);
	backlwheel2_3->child(backwheelgroup2_3);
	bottomsng2_3->add(backlwheel2_3);
	backlwheel2_3->initial_mat(transm2);
	GsModel& torus28 = *mymodel;
	SnModel* backrwheel_sn2_3 = new SnModel(&torus28);
	transm2.setrans(-5.0f, -1.0f, -4.5f);
	SnGroup* backrwheelgroup2_3 = new SnGroup;
	backrwheelgroup2_3->add(backrwheel_sn2_3);
	backrwheel2_3->child(backrwheelgroup2_3);
	bottomsng2_3->add(backrwheel2_3);
	backrwheel2_3->initial_mat(transm2);

	//fourth car 
	//top part of car
	SnPrimitive* tcar_sn2_4 = new SnPrimitive(GsPrimitive::Box, 3.6f, 2.1f, 4.45f);
	tcar_sn2_4->prim().material.diffuse = GsColor::magenta;
	transm.setrans(35.0f, 0.0f, 0.0f);
	SnGroup* topgroup2_4 = new SnGroup;
	topgroup2_4->add(tcar_sn2_4);
	top2_4->child(topgroup2_4);
	top2_4->initial_mat(transm);

	//body of car
	SnPrimitive* bcar_sn2_4 = new SnPrimitive(GsPrimitive::Box, 6.0f, 1.5f, 4.5f);
	bcar_sn2_4->prim().material.diffuse = GsColor::blue;
	transm2.setrans(0.0f, -2.0f, 0.0f);
	SnGroup* bottomsng2_4 = new SnGroup;
	bottomsng2_4->add(bcar_sn2_4);
	bottom2_4->child(bottomsng2_4);
	topgroup2_4->add(bottom2_4);
	bottom2_4->initial_mat(transm2);
	
	//front wheels - 29,30,31,32
	GsModel& torus29 = *mymodel;
	SnModel* frontlwheel_sn2_4 = new SnModel(&torus29);
	transm2.setrans(5.0f, -1.0f, 4.5f);
	SnGroup* flwheelgroup2_4 = new SnGroup;
	flwheelgroup2_4->add(frontlwheel_sn2_4);
	frontlwheel2_4->child(flwheelgroup2_4);
	bottomsng2_4->add(frontlwheel2_4);
	frontlwheel2_4->initial_mat(transm2);
	GsModel& torus30 = *mymodel;
	SnModel* frontrwheel_sn2_4 = new SnModel(&torus30);
	transm2.setrans(5.0f, -1.0f, -4.5f);
	SnGroup* frwheelgroup2_4 = new SnGroup;
	frwheelgroup2_4->add(frontrwheel_sn2_4);
	frontrwheel2_4->child(frwheelgroup2_4);
	bottomsng2_4->add(frontrwheel2_4);
	frontrwheel2_4->initial_mat(transm2);
	
	//back wheels 
	GsModel& torus31 = *mymodel;
	SnModel* backlwheel_sn2_4 = new SnModel(&torus31);
	transm2.setrans(-5.0f, -1.0f, 4.5f);
	SnGroup* backwheelgroup2_4 = new SnGroup;
	backwheelgroup2_4->add(backlwheel_sn2_4);
	backlwheel2_4->child(backwheelgroup2_4);
	bottomsng2_4->add(backlwheel2_4);
	backlwheel2_4->initial_mat(transm2);
	GsModel& torus32 = *mymodel;
	SnModel* backrwheel_sn2_4 = new SnModel(&torus32);
	transm2.setrans(-5.0f, -1.0f, -4.5f);
	SnGroup* backrwheelgroup2_4 = new SnGroup;
	backrwheelgroup2_4->add(backrwheel_sn2_4);
	backrwheel2_4->child(backrwheelgroup2_4);
	bottomsng2_4->add(backrwheel2_4);
	backrwheel2_4->initial_mat(transm2);

	topgroup2_1->add(top2_2);
	topgroup2_2->add(top2_3);
	topgroup2_3->add(top2_4);
}

void MyViewer::buildthirdrow() {
	SnPrimitive* tcar_sn3_1 = new SnPrimitive(GsPrimitive::Box, 3.6f, 2.1f, 4.45f);
	tcar_sn3_1->prim().material.diffuse = GsColor::magenta;
	transm3.setrans(-55.0f, 4.5f, 20.0f);
	SnGroup* topgroup3_1 = new SnGroup;
	topgroup3_1->add(tcar_sn3_1);
	top3_1->child(topgroup3_1);
	top3_1->initial_mat(transm3);
	rootg()->add(top3_1);

	//body of car
	SnPrimitive* bcar_sn3_1 = new SnPrimitive(GsPrimitive::Box, 6.0f, 1.5f, 4.5f);
	bcar_sn3_1->prim().material.diffuse = GsColor::blue;
	transm3.setrans(0.0f, -2.0f, 0.0f);
	SnGroup* bottomsng3_1 = new SnGroup;
	bottomsng3_1->add(bcar_sn3_1);
	bottom3_1->child(bottomsng3_1);
	topgroup3_1->add(bottom3_1);
	bottom3_1->initial_mat(transm3);

	//front wheels - 33,34,35,36
	GsModel& torus33 = *mymodel;
	SnModel* frontlwheel_sn3_1 = new SnModel(&torus33);
	transm3.setrans(5.0f, -1.0f, 4.5f);
	SnGroup* flwheelgroup3_1 = new SnGroup;
	flwheelgroup3_1->add(frontlwheel_sn3_1);
	frontlwheel3_1->child(flwheelgroup3_1);
	bottomsng3_1->add(frontlwheel3_1);
	frontlwheel3_1->initial_mat(transm3);

	GsModel& torus34 = *mymodel;
	SnModel* frontrwheel_sn3_1 = new SnModel(&torus34);
	transm3.setrans(5.0f, -1.0f, -4.5f);
	SnGroup* frwheelgroup3_1 = new SnGroup;
	frwheelgroup3_1->add(frontrwheel_sn3_1);
	frontrwheel3_1->child(frwheelgroup3_1);
	bottomsng3_1->add(frontrwheel3_1);
	frontrwheel3_1->initial_mat(transm3);

	//back wheels 
	GsModel& torus35 = *mymodel;
	SnModel* backlwheel_sn3_1 = new SnModel(&torus35);
	transm3.setrans(-5.0f, -1.0f, 4.5f);
	SnGroup* backwheelgroup3_1 = new SnGroup;
	backwheelgroup3_1->add(backlwheel_sn3_1);
	backlwheel3_1->child(backwheelgroup3_1);
	bottomsng3_1->add(backlwheel3_1);
	backlwheel3_1->initial_mat(transm3);
	GsModel& torus36 = *mymodel;
	SnModel* backrwheel_sn3_1 = new SnModel(&torus36);
	transm3.setrans(-5.0f, -1.0f, -4.5f);
	SnGroup* backrwheelgroup3_1 = new SnGroup;
	backrwheelgroup3_1->add(backrwheel_sn3_1);
	backrwheel3_1->child(backwheelgroup3_1);
	bottomsng3_1->add(backrwheel2_1);
	backrwheel3_1->initial_mat(transm3);

	//second car 
	//top part of car
	SnPrimitive* tcar_sn3_2 = new SnPrimitive(GsPrimitive::Box, 3.6f, 2.1f, 4.45f);
	tcar_sn3_2->prim().material.diffuse = GsColor::magenta;
	transm3.setrans(35.0f, 0.0f, 0.0f);
	SnGroup* topgroup3_2 = new SnGroup;
	topgroup3_2->add(tcar_sn3_2);
	top3_2->child(topgroup3_2);
	top3_2->initial_mat(transm3);

	//body of car
	SnPrimitive* bcar_sn3_2 = new SnPrimitive(GsPrimitive::Box, 6.0f, 1.5f, 4.5f);
	bcar_sn3_2->prim().material.diffuse = GsColor::blue;
	transm3.setrans(0.0f, -2.0f, 0.0f);
	SnGroup* bottomsng3_2 = new SnGroup;
	bottomsng3_2->add(bcar_sn3_2);
	bottom3_2->child(bottomsng3_2);
	topgroup3_2->add(bottom3_2);
	bottom3_2->initial_mat(transm3);

	//front wheels - 39,40,41,42
	GsModel& torus39 = *mymodel;
	SnModel* frontlwheel_sn3_2 = new SnModel(&torus39);
	transm3.setrans(5.0f, -1.0f, 4.5f);
	SnGroup* flwheelgroup3_2 = new SnGroup;
	flwheelgroup3_2->add(frontlwheel_sn3_2);
	frontlwheel3_2->child(flwheelgroup3_2);
	bottomsng3_2->add(frontlwheel3_2);
	frontlwheel3_2->initial_mat(transm3);
	GsModel& torus40 = *mymodel;
	SnModel* frontrwheel_sn3_2 = new SnModel(&torus40);
	transm3.setrans(5.0f, -1.0f, -4.5f);
	SnGroup* frwheelgroup3_2 = new SnGroup;
	frwheelgroup3_2->add(frontrwheel_sn3_2);
	frontrwheel3_2->child(frwheelgroup3_2);
	bottomsng3_2->add(frontrwheel3_2);
	frontrwheel3_2->initial_mat(transm3);

	//back wheels 
	GsModel& torus41 = *mymodel;
	SnModel* backlwheel_sn3_2 = new SnModel(&torus41);
	transm3.setrans(-5.0f, -1.0f, 4.5f);
	SnGroup* backwheelgroup3_2 = new SnGroup;
	backwheelgroup3_2->add(backlwheel_sn3_2);
	backlwheel3_2->child(backwheelgroup3_2);
	bottomsng3_2->add(backlwheel3_2);
	backlwheel3_2->initial_mat(transm3);
	GsModel& torus42 = *mymodel;
	SnModel* backrwheel_sn3_2 = new SnModel(&torus42);
	transm3.setrans(-5.0f, -1.0f, -4.5f);
	SnGroup* backrwheelgroup3_2 = new SnGroup;
	backrwheelgroup3_2->add(backrwheel_sn3_2);
	backrwheel3_2->child(backrwheelgroup3_2);
	bottomsng3_2->add(backrwheel3_2);
	backrwheel3_2->initial_mat(transm3);

	//third car 
	//top part of car
	SnPrimitive* tcar_sn3_3 = new SnPrimitive(GsPrimitive::Box, 3.6f, 2.1f, 4.45f);
	tcar_sn3_3->prim().material.diffuse = GsColor::magenta;
	transm3.setrans(35.0f, 0.0f, 0.0f);
	SnGroup* topgroup3_3 = new SnGroup;
	topgroup3_3->add(tcar_sn3_3);
	top3_3->child(topgroup3_3);
	top3_3->initial_mat(transm3);

	//body of car
	SnPrimitive* bcar_sn3_3 = new SnPrimitive(GsPrimitive::Box, 6.0f, 1.5f, 4.5f);
	bcar_sn3_3->prim().material.diffuse = GsColor::blue;
	transm3.setrans(0.0f, -2.0f, 0.0f);
	SnGroup* bottomsng3_3 = new SnGroup;
	bottomsng3_3->add(bcar_sn3_3);
	bottom3_3->child(bottomsng3_3);
	topgroup3_3->add(bottom3_3);
	bottom3_3->initial_mat(transm3);

	//front wheels - 43,44,45,46
	GsModel& torus43 = *mymodel;
	SnModel* frontlwheel_sn3_3 = new SnModel(&torus43);
	transm3.setrans(5.0f, -1.0f, 4.5f);
	SnGroup* flwheelgroup3_3 = new SnGroup;
	flwheelgroup3_3->add(frontlwheel_sn3_3);
	frontlwheel3_3->child(flwheelgroup3_3);
	bottomsng3_3->add(frontlwheel3_3);
	frontlwheel3_3->initial_mat(transm3);
	GsModel& torus44 = *mymodel;
	SnModel* frontrwheel_sn3_3 = new SnModel(&torus44);
	transm3.setrans(5.0f, -1.0f, -4.5f);
	SnGroup* frwheelgroup3_3 = new SnGroup;
	frwheelgroup3_3->add(frontrwheel_sn3_3);
	frontrwheel3_3->child(frwheelgroup3_3);
	bottomsng3_3->add(frontrwheel3_3);
	frontrwheel3_3->initial_mat(transm3);

	//back wheels 
	GsModel& torus45 = *mymodel;
	SnModel* backlwheel_sn3_3 = new SnModel(&torus45);
	transm3.setrans(-5.0f, -1.0f, 4.5f);
	SnGroup* backwheelgroup3_3 = new SnGroup;
	backwheelgroup3_3->add(backlwheel_sn3_3);
	backlwheel3_3->child(backwheelgroup3_3);
	bottomsng3_3->add(backlwheel3_3);
	backlwheel3_3->initial_mat(transm3);
	GsModel& torus46 = *mymodel;
	SnModel* backrwheel_sn3_3 = new SnModel(&torus46);
	transm3.setrans(-5.0f, -1.0f, -4.5f);
	SnGroup* backrwheelgroup3_3 = new SnGroup;
	backrwheelgroup3_3->add(backrwheel_sn3_3);
	backrwheel3_3->child(backrwheelgroup3_3);
	bottomsng3_3->add(backrwheel3_3);
	backrwheel3_3->initial_mat(transm3);

	//fourth car 
	//top part of car
	SnPrimitive* tcar_sn3_4 = new SnPrimitive(GsPrimitive::Box, 3.6f, 2.1f, 4.45f);
	tcar_sn3_4->prim().material.diffuse = GsColor::magenta;
	transm3.setrans(35.0f, 0.0f, 0.0f);
	SnGroup* topgroup3_4 = new SnGroup;
	topgroup3_4->add(tcar_sn3_4);
	top3_4->child(topgroup3_4);
	top3_4->initial_mat(transm3);

	//body of car
	SnPrimitive* bcar_sn3_4 = new SnPrimitive(GsPrimitive::Box, 6.0f, 1.5f, 4.5f);
	bcar_sn3_4->prim().material.diffuse = GsColor::blue;
	transm3.setrans(0.0f, -2.0f, 0.0f);
	SnGroup* bottomsng3_4 = new SnGroup;
	bottomsng3_4->add(bcar_sn3_4);
	bottom3_4->child(bottomsng3_4);
	topgroup3_4->add(bottom3_4);
	bottom3_4->initial_mat(transm3);

	//front wheels - 47,48,49,50
	GsModel& torus47 = *mymodel;
	SnModel* frontlwheel_sn3_4 = new SnModel(&torus47);
	transm3.setrans(5.0f, -1.0f, 4.5f);
	SnGroup* flwheelgroup3_4 = new SnGroup;
	flwheelgroup3_4->add(frontlwheel_sn3_4);
	frontlwheel3_4->child(flwheelgroup3_4);
	bottomsng3_4->add(frontlwheel2_4);
	frontlwheel3_4->initial_mat(transm3);
	GsModel& torus48 = *mymodel;
	SnModel* frontrwheel_sn3_4 = new SnModel(&torus48);
	transm3.setrans(5.0f, -1.0f, -4.5f);
	SnGroup* frwheelgroup3_4 = new SnGroup;
	frwheelgroup3_4->add(frontrwheel_sn3_4);
	frontrwheel3_4->child(frwheelgroup3_4);
	bottomsng3_4->add(frontrwheel3_4);
	frontrwheel3_4->initial_mat(transm3);

	//back wheels 
	GsModel& torus49 = *mymodel;
	SnModel* backlwheel_sn3_4 = new SnModel(&torus49);
	transm3.setrans(-5.0f, -1.0f, 4.5f);
	SnGroup* backwheelgroup3_4 = new SnGroup;
	backwheelgroup3_4->add(backlwheel_sn3_4);
	backlwheel3_4->child(backwheelgroup3_4);
	bottomsng3_4->add(backlwheel3_4);
	backlwheel3_4->initial_mat(transm3);
	GsModel& torus50 = *mymodel;
	SnModel* backrwheel_sn3_4 = new SnModel(&torus50);
	transm3.setrans(-5.0f, -1.0f, -4.5f);
	SnGroup* backrwheelgroup3_4 = new SnGroup;
	backrwheelgroup3_4->add(backrwheel_sn3_4);
	backrwheel3_4->child(backrwheelgroup3_4);
	bottomsng3_4->add(backrwheel3_4);
	backrwheel3_4->initial_mat(transm3);

	topgroup3_1->add(top3_2);
	topgroup3_2->add(top3_3);
	topgroup3_3->add(top3_4);
}
void MyViewer::buildfourthrow() {}
void MyViewer::buildfifthrow() {}
void MyViewer::buildsixthrow() {}


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
				camera().eye.z -= 0.05f;
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

	
