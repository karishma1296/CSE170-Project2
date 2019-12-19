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

/////////////*PERSON MANIP*///////////////////
SnManipulator* left_leg = new SnManipulator;
SnManipulator* right_leg = new SnManipulator;
SnManipulator* right_hand = new SnManipulator;
SnManipulator* left_hand = new SnManipulator;
SnManipulator* h_head = new SnManipulator;
SnManipulator* h_neck = new SnManipulator;
SnManipulator* h_hips = new SnManipulator;
SnManipulator* h_chest = new SnManipulator;


/////////////*CAR MANIPS*///////////////////
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
//third row
SnManipulator* top3_1 = new SnManipulator;
SnManipulator* bottom3_1 = new SnManipulator;
SnManipulator* frontlwheel3_1 = new SnManipulator;
SnManipulator* frontrwheel3_1 = new SnManipulator;
SnManipulator* backlwheel3_1 = new SnManipulator;
SnManipulator* backrwheel3_1 = new SnManipulator;

//fourth row
SnManipulator* top4_1 = new SnManipulator;
SnManipulator* bottom4_1 = new SnManipulator;
SnManipulator* frontlwheel4_1 = new SnManipulator;
SnManipulator* frontrwheel4_1 = new SnManipulator;
SnManipulator* backlwheel4_1 = new SnManipulator;
SnManipulator* backrwheel4_1 = new SnManipulator;

//fifth row
SnManipulator* top5_1 = new SnManipulator;
SnManipulator* bottom5_1 = new SnManipulator;
SnManipulator* frontlwheel5_1 = new SnManipulator;
SnManipulator* frontrwheel5_1 = new SnManipulator;
SnManipulator* backlwheel5_1 = new SnManipulator;
SnManipulator* backrwheel5_1 = new SnManipulator;

SnManipulator* top5_2 = new SnManipulator;
SnManipulator* bottom5_2 = new SnManipulator;
SnManipulator* frontlwheel5_2 = new SnManipulator;
SnManipulator* frontrwheel5_2 = new SnManipulator;
SnManipulator* backlwheel5_2 = new SnManipulator;
SnManipulator* backrwheel5_2 = new SnManipulator;

//sixth row
SnManipulator* top6_1 = new SnManipulator;
SnManipulator* bottom6_1 = new SnManipulator;
SnManipulator* frontlwheel6_1 = new SnManipulator;
SnManipulator* frontrwheel6_1 = new SnManipulator;
SnManipulator* backlwheel6_1 = new SnManipulator;
SnManipulator* backrwheel6_1 = new SnManipulator;

SnManipulator* top6_2 = new SnManipulator;
SnManipulator* bottom6_2 = new SnManipulator;
SnManipulator* frontlwheel6_2 = new SnManipulator;
SnManipulator* frontrwheel6_2 = new SnManipulator;
SnManipulator* backlwheel6_2 = new SnManipulator;
SnManipulator* backrwheel6_2 = new SnManipulator;


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
	xpos = 0.0f;
	ypos = 0.0f;
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
	p = new SnPrimitive(GsPrimitive::Box, 66.0f, 0.01f, 66.0f);
	p->prim().material.diffuse = GsColor::lightgray;
	add_model(p, GsVec(0.0f, -0.3f, 1.0f));

	/*SnModel* m = (SnModel*)p;
	GsModel* mm = m->model();

	GsModel::Group& g = *mm->G.push();
	g.fi = 0;
	g.fn = mm->F.size();
	g.dmap = new GsModel::Texture;
	g.dmap->fname.set("../street.jpg");

	mm->T.push(GsVec2(-66, -66));
	mm->T.push(GsVec2(-66, 66));
	mm->T.push(GsVec2(66, -66));
	mm->T.push(GsVec2(66, 66));

	mm->M.push().init();

	mm->set_mode(GsModel::Smooth, GsModel::PerGroupMtl);
	mm->textured = true;*/

	buildfirstrow();
	buildsecondrow();
	buildthirdrow();
	buildfourthrow();
	buildfifthrow();
	buildsixthrow();
	//buildenv();
	
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
	transm.setrans(-45.0f, 4.5f, 50.0f);

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
	transm.setrans(0.0f, 4.5f, 50.0f);
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
	transm.setrans(45.0f, 4.5f, 50.0f);
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
	rootg()->add(top1_2); rootg()->add(top1_3);

}

void MyViewer::buildsecondrow() {
	SnPrimitive* tcar_sn2_1 = new SnPrimitive(GsPrimitive::Box, 3.6f, 2.1f, 4.45f);
	tcar_sn2_1->prim().material.diffuse = GsColor::magenta;
	transm2.setrans(-30.0f, 4.5f, 35.0f);
	SnGroup* topgroup2_1 = new SnGroup;
	topgroup2_1->add(tcar_sn2_1);
	top2_1->child(topgroup2_1);
	top2_1->initial_mat(transm2);

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
	transm2.setrans(30.0f, 4.5f, 35.0f);
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

	rootg()->add(top2_1); rootg()->add(top2_2);
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
	//rootg()->add(top3_2); rootg()->add(top3_3); rootg()->add(top3_4);
}
void MyViewer::buildfourthrow() {
	SnPrimitive* tcar_sn4_1 = new SnPrimitive(GsPrimitive::Box, 3.6f, 2.1f, 4.45f);
	tcar_sn4_1->prim().material.diffuse = GsColor::magenta;
	transm4.setrans(-55.0f, 4.5f, -15.0f);
	SnGroup* topgroup4_1 = new SnGroup;
	topgroup4_1->add(tcar_sn4_1);
	top4_1->child(topgroup4_1);
	top4_1->initial_mat(transm4);
	rootg()->add(top4_1);

	//body of car
	SnPrimitive* bcar_sn4_1 = new SnPrimitive(GsPrimitive::Box, 6.0f, 1.5f, 4.5f);
	bcar_sn4_1->prim().material.diffuse = GsColor::blue;
	transm4.setrans(0.0f, -2.0f, 0.0f);
	SnGroup* bottomsng4_1 = new SnGroup;
	bottomsng4_1->add(bcar_sn4_1);
	bottom4_1->child(bottomsng4_1);
	topgroup4_1->add(bottom4_1);
	bottom4_1->initial_mat(transm4);

	//front wheels - 51,52,53,54
	GsModel& torus51 = *mymodel;
	SnModel* frontlwheel_sn4_1 = new SnModel(&torus51);
	transm4.setrans(5.0f, -1.0f, 4.5f);
	SnGroup* flwheelgroup4_1 = new SnGroup;
	flwheelgroup4_1->add(frontlwheel_sn4_1);
	frontlwheel4_1->child(flwheelgroup4_1);
	bottomsng4_1->add(frontlwheel3_1);
	frontlwheel4_1->initial_mat(transm4);

	GsModel& torus52 = *mymodel;
	SnModel* frontrwheel_sn4_1 = new SnModel(&torus52);
	transm4.setrans(5.0f, -1.0f, -4.5f);
	SnGroup* frwheelgroup4_1 = new SnGroup;
	frwheelgroup4_1->add(frontrwheel_sn4_1);
	frontrwheel4_1->child(frwheelgroup4_1);
	bottomsng4_1->add(frontrwheel4_1);
	frontrwheel4_1->initial_mat(transm4);

	//back wheels 
	GsModel& torus53 = *mymodel;
	SnModel* backlwheel_sn4_1 = new SnModel(&torus53);
	transm4.setrans(-5.0f, -1.0f, 4.5f);
	SnGroup* backwheelgroup4_1 = new SnGroup;
	backwheelgroup4_1->add(backlwheel_sn4_1);
	backlwheel3_1->child(backwheelgroup4_1);
	bottomsng4_1->add(backlwheel3_1);
	backlwheel4_1->initial_mat(transm4);
	GsModel& torus54 = *mymodel;
	SnModel* backrwheel_sn4_1 = new SnModel(&torus54);
	transm4.setrans(-5.0f, -1.0f, -4.5f);
	SnGroup* backrwheelgroup4_1 = new SnGroup;
	backrwheelgroup4_1->add(backrwheel_sn4_1);
	backrwheel4_1->child(backwheelgroup4_1);
	bottomsng4_1->add(backrwheel4_1);
	backrwheel4_1->initial_mat(transm4);

}
void MyViewer::buildfifthrow() {
	SnPrimitive* tcar_sn5_1 = new SnPrimitive(GsPrimitive::Box, 3.6f, 2.1f, 4.45f);
	tcar_sn5_1->prim().material.diffuse = GsColor::magenta;
	transm5.setrans(-55.0f, 4.5f, -30.0f);
	SnGroup* topgroup5_1 = new SnGroup;
	topgroup5_1->add(tcar_sn5_1);
	top5_1->child(topgroup5_1);
	top5_1->initial_mat(transm5);

	//body of car
	SnPrimitive* bcar_sn5_1 = new SnPrimitive(GsPrimitive::Box, 6.0f, 1.5f, 4.5f);
	bcar_sn5_1->prim().material.diffuse = GsColor::blue;
	transm5.setrans(0.0f, -2.0f, 0.0f);
	SnGroup* bottomsng5_1 = new SnGroup;
	bottomsng5_1->add(bcar_sn5_1);
	bottom5_1->child(bottomsng5_1);
	topgroup5_1->add(bottom5_1);
	bottom5_1->initial_mat(transm5);

	//front wheels - 67,68,69,70
	GsModel& torus67 = *mymodel;
	SnModel* frontlwheel_sn5_1 = new SnModel(&torus67);
	transm5.setrans(5.0f, -1.0f, 4.5f);
	SnGroup* flwheelgroup5_1 = new SnGroup;
	flwheelgroup5_1->add(frontlwheel_sn5_1);
	frontlwheel5_1->child(flwheelgroup5_1);
	bottomsng5_1->add(frontlwheel5_1);
	frontlwheel5_1->initial_mat(transm5);

	GsModel& torus68 = *mymodel;
	SnModel* frontrwheel_sn5_1 = new SnModel(&torus68);
	transm5.setrans(5.0f, -1.0f, -4.5f);
	SnGroup* frwheelgroup5_1 = new SnGroup;
	frwheelgroup5_1->add(frontrwheel_sn5_1);
	frontrwheel5_1->child(frwheelgroup5_1);
	bottomsng5_1->add(frontrwheel5_1);
	frontrwheel5_1->initial_mat(transm5);

	//back wheels 
	GsModel& torus69 = *mymodel;
	SnModel* backlwheel_sn5_1 = new SnModel(&torus69);
	transm5.setrans(-5.0f, -1.0f, 4.5f);
	SnGroup* backwheelgroup5_1 = new SnGroup;
	backwheelgroup5_1->add(backlwheel_sn5_1);
	backlwheel5_1->child(backwheelgroup5_1);
	bottomsng5_1->add(backlwheel5_1);
	backlwheel5_1->initial_mat(transm5);
	GsModel& torus70 = *mymodel;
	SnModel* backrwheel_sn5_1 = new SnModel(&torus70);
	transm5.setrans(-5.0f, -1.0f, -4.5f);
	SnGroup* backrwheelgroup5_1 = new SnGroup;
	backrwheelgroup5_1->add(backrwheel_sn5_1);
	backrwheel5_1->child(backwheelgroup5_1);
	bottomsng5_1->add(backrwheel5_1);
	backrwheel5_1->initial_mat(transm5);

	//second car 
	//top part of car
	SnPrimitive* tcar_sn5_2 = new SnPrimitive(GsPrimitive::Box, 3.6f, 2.1f, 4.45f);
	tcar_sn5_2->prim().material.diffuse = GsColor::magenta;
	transm5.setrans(10.0f, 4.5f, -30.0f);
	SnGroup* topgroup5_2 = new SnGroup;
	topgroup5_2->add(tcar_sn5_2);
	top5_2->child(topgroup5_2);
	top5_2->initial_mat(transm5);

	//body of car
	SnPrimitive* bcar_sn5_2 = new SnPrimitive(GsPrimitive::Box, 6.0f, 1.5f, 4.5f);
	bcar_sn5_2->prim().material.diffuse = GsColor::blue;
	transm5.setrans(0.0f, -2.0f, 0.0f);
	SnGroup* bottomsng5_2 = new SnGroup;
	bottomsng5_2->add(bcar_sn5_2);
	bottom5_2->child(bottomsng5_2);
	topgroup5_2->add(bottom5_2);
	bottom5_2->initial_mat(transm5);

	//front wheels - 71,72,73,74
	GsModel& torus71 = *mymodel;
	SnModel* frontlwheel_sn5_2 = new SnModel(&torus71);
	transm5.setrans(5.0f, -1.0f, 4.5f);
	SnGroup* flwheelgroup5_2 = new SnGroup;
	flwheelgroup5_2->add(frontlwheel_sn5_2);
	frontlwheel5_2->child(flwheelgroup5_2);
	bottomsng5_2->add(frontlwheel5_2);
	frontlwheel5_2->initial_mat(transm5);
	GsModel& torus72 = *mymodel;
	SnModel* frontrwheel_sn5_2 = new SnModel(&torus72);
	transm5.setrans(5.0f, -1.0f, -4.5f);
	SnGroup* frwheelgroup5_2 = new SnGroup;
	frwheelgroup5_2->add(frontrwheel_sn5_2);
	frontrwheel5_2->child(frwheelgroup5_2);
	bottomsng5_2->add(frontrwheel5_2);
	frontrwheel5_2->initial_mat(transm5);

	//back wheels 
	GsModel& torus73 = *mymodel;
	SnModel* backlwheel_sn5_2 = new SnModel(&torus73);
	transm5.setrans(-5.0f, -1.0f, 4.5f);
	SnGroup* backwheelgroup5_2 = new SnGroup;
	backwheelgroup5_2->add(backlwheel_sn5_2);
	backlwheel5_2->child(backwheelgroup5_2);
	bottomsng5_2->add(backlwheel5_2);
	backlwheel5_2->initial_mat(transm5);
	GsModel& torus74 = *mymodel;
	SnModel* backrwheel_sn5_2 = new SnModel(&torus74);
	transm5.setrans(-5.0f, -1.0f, -4.5f);
	SnGroup* backrwheelgroup5_2 = new SnGroup;
	backrwheelgroup5_2->add(backrwheel_sn5_2);
	backrwheel5_2->child(backrwheelgroup5_2);
	bottomsng5_2->add(backrwheel5_2);
	backrwheel5_2->initial_mat(transm5);

	rootg()->add(top5_1);
	rootg()->add(top5_2);
}
void MyViewer::buildsixthrow() {
	SnPrimitive* tcar_sn6_1 = new SnPrimitive(GsPrimitive::Box, 3.6f, 2.1f, 4.45f);
	tcar_sn6_1->prim().material.diffuse = GsColor::magenta;
	transm6.setrans(-55.0f, 4.5f, -50.0f);
	SnGroup* topgroup6_1 = new SnGroup;
	topgroup6_1->add(tcar_sn6_1);
	top6_1->child(topgroup6_1);
	top6_1->initial_mat(transm6);
	rootg()->add(top6_1);

	//body of car
	SnPrimitive* bcar_sn6_1 = new SnPrimitive(GsPrimitive::Box, 6.0f, 1.5f, 4.5f);
	bcar_sn6_1->prim().material.diffuse = GsColor::blue;
	transm6.setrans(0.0f, -2.0f, 0.0f);
	SnGroup* bottomsng6_1 = new SnGroup;
	bottomsng6_1->add(bcar_sn6_1);
	bottom6_1->child(bottomsng6_1);
	topgroup6_1->add(bottom6_1);
	bottom6_1->initial_mat(transm6);

	//front wheels - 83,84,85,86
	GsModel& torus83 = *mymodel;
	SnModel* frontlwheel_sn6_1 = new SnModel(&torus83);
	transm6.setrans(5.0f, -1.0f, 4.5f);
	SnGroup* flwheelgroup6_1 = new SnGroup;
	flwheelgroup6_1->add(frontlwheel_sn6_1);
	frontlwheel6_1->child(flwheelgroup6_1);
	bottomsng6_1->add(frontlwheel6_1);
	frontlwheel6_1->initial_mat(transm6);

	GsModel& torus84 = *mymodel;
	SnModel* frontrwheel_sn6_1 = new SnModel(&torus84);
	transm6.setrans(5.0f, -1.0f, -4.5f);
	SnGroup* frwheelgroup6_1 = new SnGroup;
	frwheelgroup6_1->add(frontrwheel_sn6_1);
	frontrwheel6_1->child(frwheelgroup6_1);
	bottomsng6_1->add(frontrwheel6_1);
	frontrwheel6_1->initial_mat(transm6);

	//back wheels 
	GsModel& torus85 = *mymodel;
	SnModel* backlwheel_sn6_1 = new SnModel(&torus85);
	transm6.setrans(-5.0f, -1.0f, 4.5f);
	SnGroup* backwheelgroup6_1 = new SnGroup;
	backwheelgroup6_1->add(backlwheel_sn6_1);
	backlwheel6_1->child(backwheelgroup6_1);
	bottomsng6_1->add(backlwheel6_1);
	backlwheel6_1->initial_mat(transm6);
	GsModel& torus86 = *mymodel;
	SnModel* backrwheel_sn6_1 = new SnModel(&torus86);
	transm6.setrans(-5.0f, -1.0f, -4.5f);
	SnGroup* backrwheelgroup6_1 = new SnGroup;
	backrwheelgroup6_1->add(backrwheel_sn6_1);
	backrwheel6_1->child(backwheelgroup6_1);
	bottomsng6_1->add(backrwheel6_1);
	backrwheel6_1->initial_mat(transm6);

	//second car 
	//top part of car
	SnPrimitive* tcar_sn6_2 = new SnPrimitive(GsPrimitive::Box, 3.6f, 2.1f, 4.45f);
	tcar_sn6_2->prim().material.diffuse = GsColor::magenta;
	transm6.setrans(-20.0f, 4.5f, -50.0f);
	SnGroup* topgroup6_2 = new SnGroup;
	topgroup6_2->add(tcar_sn6_2);
	top6_2->child(topgroup6_2);
	top6_2->initial_mat(transm6);

	//body of car
	SnPrimitive* bcar_sn6_2 = new SnPrimitive(GsPrimitive::Box, 6.0f, 1.5f, 4.5f);
	bcar_sn6_2->prim().material.diffuse = GsColor::blue;
	transm6.setrans(0.0f, -2.0f, 0.0f);
	SnGroup* bottomsng6_2 = new SnGroup;
	bottomsng6_2->add(bcar_sn6_2);
	bottom6_2->child(bottomsng6_2);
	topgroup6_2->add(bottom6_2);
	bottom6_2->initial_mat(transm6);

	//front wheels - 87,88,89,90
	GsModel& torus87 = *mymodel;
	SnModel* frontlwheel_sn6_2 = new SnModel(&torus87);
	transm6.setrans(5.0f, -1.0f, 4.5f);
	SnGroup* flwheelgroup6_2 = new SnGroup;
	flwheelgroup6_2->add(frontlwheel_sn6_2);
	frontlwheel6_2->child(flwheelgroup6_2);
	bottomsng6_2->add(frontlwheel6_2);
	frontlwheel6_2->initial_mat(transm6);
	GsModel& torus88 = *mymodel;
	SnModel* frontrwheel_sn6_2 = new SnModel(&torus88);
	transm6.setrans(5.0f, -1.0f, -4.5f);
	SnGroup* frwheelgroup6_2 = new SnGroup;
	frwheelgroup6_2->add(frontrwheel_sn6_2);
	frontrwheel6_2->child(frwheelgroup6_2);
	bottomsng6_2->add(frontrwheel6_2);
	frontrwheel6_2->initial_mat(transm6);

	//back wheels 
	GsModel& torus89 = *mymodel;
	SnModel* backlwheel_sn6_2 = new SnModel(&torus89);
	transm6.setrans(-5.0f, -1.0f, 4.5f);
	SnGroup* backwheelgroup6_2 = new SnGroup;
	backwheelgroup6_2->add(backlwheel_sn6_2);
	backlwheel6_2->child(backwheelgroup6_2);
	bottomsng6_2->add(backlwheel6_2);
	backlwheel6_2->initial_mat(transm6);
	GsModel& torus90 = *mymodel;
	SnModel* backrwheel_sn6_2 = new SnModel(&torus90);
	transm6.setrans(-5.0f, -1.0f, -4.5f);
	SnGroup* backrwheelgroup6_2 = new SnGroup;
	backrwheelgroup6_2->add(backrwheel_sn6_2);
	backrwheel6_2->child(backrwheelgroup6_2);
	bottomsng6_2->add(backrwheel6_2);
	backrwheel6_2->initial_mat(transm6);
	//rootg()->add(top6_2);

}
void MyViewer::buildenv() {
	SnPrimitive* p;
	p = new SnPrimitive(GsPrimitive::Capsule, 0.2f, 1.0f, 0.2f);
	p->prim().material.diffuse = GsColor::darkgreen;
	add_model(p, GsVec(-5.0f, 2.8f, -7.0f));
	p = new SnPrimitive(GsPrimitive::Cylinder, 0.1f, 0.1f, 1.6f);
	p->prim().material.diffuse = GsColor::brown;
	add_model(p, GsVec(-5.0f, 0.9f, -7.0f));

	p = new SnPrimitive(GsPrimitive::Capsule, 0.2f, 0.8f, 0.2f);
	p->prim().material.diffuse = GsColor::green;
	add_model(p, GsVec(-4.1f, 2.5f, -6.4f));
	p = new SnPrimitive(GsPrimitive::Cylinder, 0.1f, 0.1f, 1.4f);
	p->prim().material.diffuse = GsColor::brown;
	add_model(p, GsVec(-4.1f, 0.7f, -6.4f));

	p = new SnPrimitive(GsPrimitive::Capsule, 0.2f, 0.8f, 0.2f);
	p->prim().material.diffuse = GsColor::darkgreen;
	add_model(p, GsVec(-3.1f, 2.7f, -7.0f));
	p = new SnPrimitive(GsPrimitive::Cylinder, 0.1f, 0.1f, 1.6f);
	p->prim().material.diffuse = GsColor::brown;
	add_model(p, GsVec(-3.1f, 0.9f, -7.0f));

	p = new SnPrimitive(GsPrimitive::Capsule, 0.2f, 0.8f, 0.2f);
	p->prim().material.diffuse = GsColor::green;
	add_model(p, GsVec(-3.1f, 2.5f, -6.4f));
	p = new SnPrimitive(GsPrimitive::Cylinder, 0.1f, 0.1f, 1.4f);
	p->prim().material.diffuse = GsColor::brown;
	add_model(p, GsVec(-3.1f, 0.7f, -6.4f));

	p = new SnPrimitive(GsPrimitive::Capsule, 0.2f, 0.8f, 0.2f);
	p->prim().material.diffuse = GsColor::darkgreen;
	add_model(p, GsVec(-2.1f, 2.7f, -7.0f));
	p = new SnPrimitive(GsPrimitive::Cylinder, 0.1f, 0.1f, 1.6f);
	p->prim().material.diffuse = GsColor::brown;
	add_model(p, GsVec(-2.1f, 0.9f, -7.0f));
}

void MyViewer::animatecars(){
	if (_animating) return; // avoid recursive calls
	_animating = true;

	GsMat m = top1_1->mat();
	GsMat m2 = top1_2->mat();
	GsMat m3 = top1_3->mat();
	GsMat m4 = top2_1->mat();
	GsMat m5 = top2_2->mat();
	GsMat m6 = top3_1->mat();
	GsMat m7 = top4_1->mat();
	GsMat m8 = top5_1->mat();
	GsMat m9 = top5_2->mat();
	GsMat m10 = top6_1->mat();

	double frdt = 1.0 / 30.0; // delta time to reach given number of frames per second
	double v = 4; // target velocity is 1 unit per second
	double t = 0, lt = 0, t0 = gs_time();
	do // run for a while:
	{
		while (t - lt < frdt) { ws_check(); t = gs_time() - t0; } // wait until it is time for next frame
		lt = t;		//makes speed constant
		double yinc = 1.3;

		if (m.e14 > 70.0f) m.e14 = -70.0f;
		if (m2.e14 > 70.0f) m2.e14 = -70.0f;
		if (m3.e14 > 70.0f) m3.e14 = -70.0f;
		m.e14 += (float)yinc;
		m2.e14 += (float)yinc;
		m3.e14 += (float)yinc;
		top1_1->initial_mat(m);
		top1_2->initial_mat(m2);
		top1_3->initial_mat(m3);

		//second row
		double yinc2 = 0.9;
		
		if (m4.e14 < -70.0f) m4.e14 = 70.0f;
		if (m5.e14 < -70.0f) m5.e14 = 70.0f;
		m4.e14 -= (float)yinc2;
		m5.e14 -= (float)yinc2;
		top2_1->initial_mat(m4);
		top2_2->initial_mat(m5);

		double yinc3 = 3.0;
		if (m6.e14 < -70.0f) m6.e14 = 70.0f;
		m6.e14 -= (float)yinc3;
		top3_1->initial_mat(m6);

		double yinc4 = 4.0;
		if (m7.e14 > 70.0f) m7.e14 = -70.0f;
		m7.e14 += (float)yinc4;
		top4_1->initial_mat(m7);

		if (m8.e14 < -70.0f) m8.e14 = 70.0f;
		if (m9.e14 < -70.0f) m9.e14 = 70.0f;
		m8.e14 -= (float)yinc2;
		m9.e14 -= (float)yinc2;
		top5_1->initial_mat(m8);
		top5_2->initial_mat(m9);

		double yinc5 = 5.0;
		if (m10.e14 > 70.0f) m10.e14 = -70.0f;
		m10.e14 += (float)yinc3;
		top6_1->initial_mat(m10);

		




		render(); // notify it needs redraw
		ws_check(); // redraw now
	} while (m.e24 > 0);

	
}

void MyViewer::run_animation(){
	//int a, b, c;
	//double theta = GS_2PI / 100;
	if (_animating) return; // avoid recursive calls
	_animating = true;

	//int ind = gs_random(0, rootg()->size() - 1); // pick one child
	//SnManipulator* manip = rootg()->get<SnManipulator>(ind); // access one of the manipulators
	cartrans = top1_3->mat();
	GsMat m = top1_3->mat();


	double frdt = 1.0/30.0; // delta time to reach given number of frames per second
	double v = 4; // target velocity is 1 unit per second
	double t=0, lt=0, t0=gs_time();
	do // run for a while:
	{	while ( t-lt<frdt ) { ws_check(); t=gs_time()-t0; } // wait until it is time for next frame
		double yinc = (t-lt)*v;
		//if ( t>2 ) yinc=-yinc; // after 2 secs: go down
		if (m.e14 > 65.0f) m.e14 = -65.0f;
		lt = t;
		m.e14 += (float)yinc;
	//if ( m.e14<0 ) m.e24=0; // make sure it does not go below 0
	top1_3->initial_mat ( m );
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
		xposition = 0.2f;
		persontranslation.e14 -= xposition;
		h_head->initial_mat(persontranslation);
		render();
		return 1;

	}
			  //right arrow
	case 65363: {
		persontranslation = h_head->mat();
		xposition = 0.2f;
		persontranslation.e14 += xposition;
		h_head->initial_mat(persontranslation);
		render();
		return 1;
	}
			  //foward
	case 65362: {
		persontranslation = h_head->mat();
		yposition = 0.35f;
		persontranslation.e34 -= yposition;
		h_head->initial_mat(persontranslation);
		GsVec test;
		GsVec test2;
		GsBox humanBox = h_head->box();
		float e14 = persontranslation.e14;
		float e24 = persontranslation.e24;
		float e34 = persontranslation.e34;
		GsBox b13 = top1_3->box();
		GsPnt A = GsPnt(e14, e24, e34);
		if (b13.contains(A))
			gsout << "touched bitch" << gsnl;
		gsout << A << gsnl;
	/*	test = b13.size();
		gsout << test << gsnl;

		test2 = humanBox.size();
		gsout << test2 << gsnl;
	if (humanBox.intersects(b13))
			gsout << "touched bitch!" << gsnl;*/
		render();
		return 1;
	}
			  //back
	case 65364: {
		persontranslation = h_head->mat();
		yposition = 0.35f;
		persontranslation.e34 += yposition;
		h_head->initial_mat(persontranslation);
		render();
		return 1;
	}

	case 'v': {
		/*do {
			while ();
			if ();
		} while ();

		cartrans = top1_4->mat();
		xpos = cartrans.e14;
		xpos += 1.0f;
		cartrans.e14 = xpos;
		top1_4->initial_mat(cartrans);

		if (cartrans.e14 > 66.0f) {
			cartrans.e14 = -65.0f;
			top1_4->initial_mat(cartrans);
		}

		cartrans = top1_3->mat();
		xpos = cartrans.e14;
		xpos += 1.0f;
		cartrans.e14 = xpos;
		top1_3->initial_mat(cartrans);

		if (cartrans.e14 > 66.0f) {
			cartrans.e14 = -65.0f;
			top1_3->initial_mat(cartrans);
		}

		cartrans = top1_2->mat();
		xpos = cartrans.e14;
		xpos += 1.0f;
		cartrans.e14 = xpos;
		top1_2->initial_mat(cartrans);

		if (cartrans.e14 > 66.0f) {
			cartrans.e14 = -65.0f;
			top1_2->initial_mat(cartrans);
		}

		cartrans = top1_1->mat();
		xpos = cartrans.e14;
		xpos += 1.0f;
		cartrans.e14 = xpos;
		top1_1->initial_mat(cartrans);

		if (cartrans.e14 > 66.0f) {
			cartrans.e14 = -65.0f;
			top1_1->initial_mat(cartrans);
		}
		render();*/
		return 1;
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
				//case EvAnimate: run_animation(); return 1;
				case EvAnimate: animatecars(); return 1;
				case EvExit: gs_exit();
				}
				return WsViewer::uievent(e);
			}

	
