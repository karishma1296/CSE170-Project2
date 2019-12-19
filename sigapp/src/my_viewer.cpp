# include "my_viewer.h"

# include <sigogl/ui_button.h>
# include <sigogl/ui_radio_button.h>
# include <sig/sn_primitive.h>
# include <sig/sn_transform.h>
# include <sig/sn_manipulator.h>
#include <cmath>

# include <sigogl/ws_run.h>

SnGroup* torso = new SnGroup;
int count = 0;
int control = 1;
GsModel* mymodel = new GsModel;
bool leftL = false; bool rightL = false; bool leftA = false; bool rightA = false;
bool front = false; bool back = false; bool left = false; bool right = false;
bool step = true; bool side = false; bool mode = false;
float finc = 65.0f;
float sinc = 65.0f;


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
	on = true;
	_animating = false;
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
	p->add(new UiButton("First Person", EvCam));
	p->add ( new UiButton ( "Let's Play", EvAnimate ) );
	p->add ( new UiButton ( "Exit", EvExit ) ); p->top()->separate();
}

void MyViewer::add_model(SnShape* s, GsVec p)
{
	// This method demonstrates how to add some elements to our scene graph: lines,
	// and a shape, and all in a group under a SnManipulator.
	// Therefore we are also demonstrating the use of a manipulator to allow the user to
	// change the position of the object with the mouse. If you do not need mouse interaction,
	// you can just use a SnTransform to apply a transformation instead of a SnManipulator.
	// You would then add the transform as 1st element of the group, and set g->separator(true).
	// Your scene graph should always be carefully designed according to your application needs.

	SnTransform* transform = new SnTransform;
	SnGroup* g = new SnGroup;
	SnLines* l = new SnLines;
	GsMat matrix;

	matrix.translation(p);
	//if (count == 3) {
	//	matrix.rotx(0, 1);
	//	matrix.setrans(-20, 15, 20);
	//}
	//if (count == 6) {
	//	matrix.rotx(1, 0);
	//	matrix.setrans(-30, 25, -30);
	//}
	if (count < 7) {
		torso->add(transform);
		//torso->add(s);
	}
	transform->set(matrix);
	g->add(transform);
	g->separator(true);
	g->add(s);
	g->add(l);

	// manip->visible(false); // call this to turn off mouse interaction
	count++;
	rootg()->add(g);

	////add later
	//SnManipulator* manip = new SnManipulator;
	//GsMat m;
	//m.translation ( p );
	//manip->initial_mat ( m );

	// manip->visible(false); // call this to turn off mouse interaction

	//rootg()->add(manip);
}

void MyViewer::build_scene ()
{
	SnPrimitive* p;

	// alien body construction
	p = new SnPrimitive(GsPrimitive::Ellipsoid, 2.0, 0.5);
	p->prim().material.diffuse = GsColor::darkgreen;
	add_model(p, GsVec(0, 3, 65));

	p = new SnPrimitive(GsPrimitive::Cylinder, 0.25, 0.25, 0.5);
	p->prim().material.diffuse = GsColor::blue;
	add_model(p, GsVec(0, 5, 65));

	p = new SnPrimitive(GsPrimitive::Sphere, 1);
	p->prim().material.diffuse = GsColor::darkgreen;
	add_model(p, GsVec(0, 6, 65));

	//legs
	p = new SnPrimitive(GsPrimitive::Capsule, .25, .25, 1);
	p->prim().material.diffuse = GsColor::blue;
	add_model(p, GsVec(-0.5f, 1.0f, 65));

	p = new SnPrimitive(GsPrimitive::Capsule, .25, .25, 1);
	p->prim().material.diffuse = GsColor::blue;
	add_model(p, GsVec(0.5f, 1.0f, 65));

	//arms
	p = new SnPrimitive(GsPrimitive::Capsule, .25, .25, 1);
	p->prim().material.diffuse = GsColor::blue;
	add_model(p, GsVec(-1, 3.0f, 65));

	p = new SnPrimitive(GsPrimitive::Capsule, .25, .25, 1);
	p->prim().material.diffuse = GsColor::blue;
	add_model(p, GsVec(1, 3.0f, 65));
	
	//floor
	p = new SnPrimitive(GsPrimitive::Box, 66.0f, 0.01f, 66.0f);
	p->prim().material.diffuse = GsColor::darkgray;
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
	buildenv();
	
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
	tcar_sn1_2->prim().material.diffuse = GsColor::orange;
	transm.setrans(0.0f, 4.5f, 50.0f);
	SnGroup* topgroup1_2 = new SnGroup;
	topgroup1_2->add(tcar_sn1_2);
	top1_2->child(topgroup1_2);
	top1_2->initial_mat(transm);

	//body of car
	SnPrimitive* bcar_sn1_2 = new SnPrimitive(GsPrimitive::Box, 6.0f, 1.5f, 4.5f);
	bcar_sn1_2->prim().material.diffuse = GsColor::cyan;
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
	tcar_sn1_3->prim().material.diffuse = GsColor::green;
	transm.setrans(45.0f, 4.5f, 50.0f);
	SnGroup* topgroup1_3 = new SnGroup;
	topgroup1_3->add(tcar_sn1_3);
	top1_3->child(topgroup1_3);
	top1_3->initial_mat(transm);

	//body of car
	SnPrimitive* bcar_sn1_3 = new SnPrimitive(GsPrimitive::Box, 6.0f, 1.5f, 4.5f);
	bcar_sn1_3->prim().material.diffuse = GsColor::red;
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
	tcar_sn2_1->prim().material.diffuse = GsColor::cyan;
	transm2.setrans(-30.0f, 4.5f, 32.0f);
	SnGroup* topgroup2_1 = new SnGroup;
	topgroup2_1->add(tcar_sn2_1);
	top2_1->child(topgroup2_1);
	top2_1->initial_mat(transm2);

	//body of car
	SnPrimitive* bcar_sn2_1 = new SnPrimitive(GsPrimitive::Box, 6.0f, 1.5f, 4.5f);
	bcar_sn2_1->prim().material.diffuse = GsColor::orange;
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
	tcar_sn2_2->prim().material.diffuse = GsColor::orange;
	transm2.setrans(30.0f, 4.5f, 32.0f);
	SnGroup* topgroup2_2 = new SnGroup;
	topgroup2_2->add(tcar_sn2_2);
	top2_2->child(topgroup2_2);
	top2_2->initial_mat(transm2);

	//body of car
	SnPrimitive* bcar_sn2_2 = new SnPrimitive(GsPrimitive::Box, 6.0f, 1.5f, 4.5f);
	bcar_sn2_2->prim().material.diffuse = GsColor::yellow;
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
	tcar_sn3_1->prim().material.diffuse = GsColor::green;
	transm3.setrans(-55.0f, 4.5f, 15.0f);
	SnGroup* topgroup3_1 = new SnGroup;
	topgroup3_1->add(tcar_sn3_1);
	top3_1->child(topgroup3_1);
	top3_1->initial_mat(transm3);
	rootg()->add(top3_1);

	//body of car
	SnPrimitive* bcar_sn3_1 = new SnPrimitive(GsPrimitive::Box, 6.0f, 1.5f, 4.5f);
	bcar_sn3_1->prim().material.diffuse = GsColor::lightblue;
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
	tcar_sn4_1->prim().material.diffuse = GsColor::lightblue;
	transm4.setrans(-55.0f, 4.5f, -10.0f);
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
	tcar_sn5_1->prim().material.diffuse = GsColor::yellow;
	transm5.setrans(-55.0f, 4.5f, -30.0f);
	SnGroup* topgroup5_1 = new SnGroup;
	topgroup5_1->add(tcar_sn5_1);
	top5_1->child(topgroup5_1);
	top5_1->initial_mat(transm5);

	//body of car
	SnPrimitive* bcar_sn5_1 = new SnPrimitive(GsPrimitive::Box, 6.0f, 1.5f, 4.5f);
	bcar_sn5_1->prim().material.diffuse = GsColor::magenta;
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
	tcar_sn5_2->prim().material.diffuse = GsColor::green;
	transm5.setrans(10.0f, 4.5f, -30.0f);
	SnGroup* topgroup5_2 = new SnGroup;
	topgroup5_2->add(tcar_sn5_2);
	top5_2->child(topgroup5_2);
	top5_2->initial_mat(transm5);

	//body of car
	SnPrimitive* bcar_sn5_2 = new SnPrimitive(GsPrimitive::Box, 6.0f, 1.5f, 4.5f);
	bcar_sn5_2->prim().material.diffuse = GsColor::darkgreen;
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
	tcar_sn6_1->prim().material.diffuse = GsColor::red;
	transm6.setrans(-55.0f, 4.5f, -50.0f);
	SnGroup* topgroup6_1 = new SnGroup;
	topgroup6_1->add(tcar_sn6_1);
	top6_1->child(topgroup6_1);
	top6_1->initial_mat(transm6);
	rootg()->add(top6_1);

	//body of car
	SnPrimitive* bcar_sn6_1 = new SnPrimitive(GsPrimitive::Box, 6.0f, 1.5f, 4.5f);
	bcar_sn6_1->prim().material.diffuse = GsColor::lightblue;
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
	p = new SnPrimitive(GsPrimitive::Capsule, 1.0f, 8.0f, 1.0f);
	p->prim().material.diffuse = GsColor::darkgreen;
	add_model(p, GsVec(-60.0f, 15.0f, -65.0f));
	p = new SnPrimitive(GsPrimitive::Cylinder, 0.5f, 0.5f, 10.0f);
	p->prim().material.diffuse = GsColor::brown;
	add_model(p, GsVec(-60.0f, 10.0f, -65.0f));

	p = new SnPrimitive(GsPrimitive::Capsule, 1.0f, 8.0f, 1.0f);
	p->prim().material.diffuse = GsColor::green;
	add_model(p, GsVec(-50.0f, 17.0f, -60.0f));
	p = new SnPrimitive(GsPrimitive::Cylinder, 0.5f, 0.5f, 10.0f);
	p->prim().material.diffuse = GsColor::brown;
	add_model(p, GsVec(-50.0f, 7.0f, -60.0f));

	p = new SnPrimitive(GsPrimitive::Capsule, 1.0f, 8.0f, 1.0f);
	p->prim().material.diffuse = GsColor::darkgreen;
	add_model(p, GsVec(-40.0f, 17.0f, -65.0f));
	p = new SnPrimitive(GsPrimitive::Cylinder, 0.5f, 0.5f, 10.0f);
	p->prim().material.diffuse = GsColor::brown;
	add_model(p, GsVec(-40.0f, 7.0f, -65.0f));

	p = new SnPrimitive(GsPrimitive::Capsule, 1.0f, 8.0f, 1.0f);
	p->prim().material.diffuse = GsColor::green;
	add_model(p, GsVec(-30.0f, 14.0f, -62.0f));
	p = new SnPrimitive(GsPrimitive::Cylinder, 0.5f, 0.5f, 7.0f);
	p->prim().material.diffuse = GsColor::brown;
	add_model(p, GsVec(-30.0f, 7.0f, -62.0f));

	p = new SnPrimitive(GsPrimitive::Capsule, 1.0f, 8.0f, 1.0f);
	p->prim().material.diffuse = GsColor::darkgreen;
	add_model(p, GsVec(-20.0f, 19.0f, -64.0f));
	p = new SnPrimitive(GsPrimitive::Cylinder, 0.5f, 0.5f, 9.0f);
	p->prim().material.diffuse = GsColor::brown;
	add_model(p, GsVec(-20.0f, 8.0f, -64.0f));


	p = new SnPrimitive(GsPrimitive::Capsule, 1.0f, 8.0f, 1.0f);
	p->prim().material.diffuse = GsColor::darkgreen;
	add_model(p, GsVec(60.0f, 15.0f, -65.0f));
	p = new SnPrimitive(GsPrimitive::Cylinder, 0.5f, 0.5f, 10.0f);
	p->prim().material.diffuse = GsColor::brown;
	add_model(p, GsVec(60.0f, 10.0f, -65.0f));

	p = new SnPrimitive(GsPrimitive::Capsule, 1.0f, 8.0f, 1.0f);
	p->prim().material.diffuse = GsColor::green;
	add_model(p, GsVec(50.0f, 17.0f, -60.0f));
	p = new SnPrimitive(GsPrimitive::Cylinder, 0.5f, 0.5f, 10.0f);
	p->prim().material.diffuse = GsColor::brown;
	add_model(p, GsVec(50.0f, 7.0f, -60.0f));

	p = new SnPrimitive(GsPrimitive::Capsule, 1.0f, 8.0f, 1.0f);
	p->prim().material.diffuse = GsColor::darkgreen;
	add_model(p, GsVec(40.0f, 17.0f, -65.0f));
	p = new SnPrimitive(GsPrimitive::Cylinder, 0.5f, 0.5f, 10.0f);
	p->prim().material.diffuse = GsColor::brown;
	add_model(p, GsVec(40.0f, 7.0f, -65.0f));

	p = new SnPrimitive(GsPrimitive::Capsule, 1.0f, 8.0f, 1.0f);
	p->prim().material.diffuse = GsColor::green;
	add_model(p, GsVec(30.0f, 14.0f, -62.0f));
	p = new SnPrimitive(GsPrimitive::Cylinder, 0.5f, 0.5f, 7.0f);
	p->prim().material.diffuse = GsColor::brown;
	add_model(p, GsVec(30.0f, 7.0f, -62.0f));

	p = new SnPrimitive(GsPrimitive::Capsule, 1.0f, 8.0f, 1.0f);
	p->prim().material.diffuse = GsColor::darkgreen;
	add_model(p, GsVec(20.0f, 19.0f, -64.0f));
	p = new SnPrimitive(GsPrimitive::Cylinder, 0.5f, 0.5f, 9.0f);
	p->prim().material.diffuse = GsColor::brown;
	add_model(p, GsVec(20.0f, 8.0f, -64.0f));

	//floor
	p = new SnPrimitive(GsPrimitive::Box, 10.0f, 0.2f, 1.5f);
	p->prim().material.diffuse = GsColor::white;
	add_model(p, GsVec(0.0f, 0.0f, 42.0f));
	add_model(p,GsVec(45.0f, 0.0f, 42.0f));
	add_model(p, GsVec(-45.0f, 0.0f, 42.0f));
	add_model(p, GsVec(-45.0f, 0.0f, 25.0f));
	add_model(p, GsVec(45.0f, 0.0f, 25.0f));
	add_model(p, GsVec(0.0f, 0.0f, 25.0f));
	add_model(p, GsVec(0.0f, 0.0f, -20.0f));
	add_model(p, GsVec(45.0f, 0.0f, -20.0f));
	add_model(p, GsVec(-45.0f, 0.0f, -20.0f));
	add_model(p, GsVec(0.0f, 0.0f, -40.0f));
	add_model(p, GsVec(45.0f, 0.0f, -40.0f));
	add_model(p, GsVec(-45.0f, 0.0f, -40.0f));

	p = new SnPrimitive(GsPrimitive::Box, 66.0f, 0.2f, 5.1f);
	p->prim().material.diffuse = GsColor::white;
	add_model(p, GsVec(0.0f, 0.0f, 65.0f));
	add_model(p, GsVec(0.0f, 0.0f, -65.0f));
}

void reset() {
	finc = 65.0f;
	sinc = 65.0f;
	SnTransform* t = torso->get<SnTransform>(0);
	SnTransform* t1 = torso->get<SnTransform>(1);
	SnTransform* t2 = torso->get<SnTransform>(2);
	SnTransform* t3 = torso->get<SnTransform>(3);
	SnTransform* t4 = torso->get<SnTransform>(4);
	SnTransform* t5 = torso->get<SnTransform>(5);
	SnTransform* t6 = torso->get<SnTransform>(6);

	GsMat m = t->get();
	GsMat m1 = t1->get();
	GsMat m2 = t2->get();
	GsMat m3 = t3->get();
	GsMat m4 = t4->get();
	GsMat m5 = t5->get();
	GsMat m6 = t6->get();

		m.e34 = finc;
		t->set(m);
		m1.e34 = finc;
		t1->set(m1);
		m2.e34 = finc;
		t2->set(m2);
		m3.e34 = finc;
		t3->set(m3);
		m4.e34 = finc;
		t4->set(m4);
		m5.e34 = finc;
		t5->set(m5);
		m6.e34 = finc;
		t6->set(m6);
		
}

bool contains(GsPnt A, GsPnt B) {
	return A.x >= B.x - 6 && A.x <= B.x + 6 && A.y >= B.y - 4.45f && A.y <= B.y + 4.45f && A.z >= B.z - 4.5f && A.z <= B.z + 4.5f;
}

void MyViewer::animatecars() {
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

	SnTransform* person = torso->get<SnTransform>(0);
	GsMat body = person->get();

	double frdt = 1.0 / 30.0; // delta time to reach given number of frames per second
	double v = 4; // target velocity is 1 unit per second
	double t = 0, lt = 0, t0 = gs_time();
	do // run for a while:
	{
		while (t - lt < frdt) { ws_check(); t = gs_time() - t0; } // wait until it is time for next frame
		lt = t;		//makes speed constant

		SnTransform* person = torso->get<SnTransform>(0);
		GsMat body = person->get();

		double yinc = 0.7;

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

		double yinc4 = 3.3;
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

		float e14 = body.e14;
		float e24 = body.e24;
		float e34 = body.e34;

		float c14 = m.e14;
		float c24 = m.e24;
		float c34 = m.e34;

		GsPnt A = GsPnt(e14, e24, e34);
		GsPnt B = GsPnt(c14, c24, c34);
		if (contains(A, B))
			reset();

		c14 = m2.e14;
		c24 = m2.e24;
		c34 = m2.e34;

		B = GsPnt(c14, c24, c34);
		if (contains(A, B))
			reset();

		c14 = m3.e14;
		c24 = m3.e24;
		c34 = m3.e34;

		B = GsPnt(c14, c24, c34);
		if (contains(A, B))
			reset();

		c14 = m4.e14;
		c24 = m4.e24;
		c34 = m4.e34;

		B = GsPnt(c14, c24, c34);
		if (contains(A, B))
			reset();

		c14 = m5.e14;
		c24 = m5.e24;
		c34 = m5.e34;

		B = GsPnt(c14, c24, c34);
		if (contains(A, B))
			reset();

		c14 = m6.e14;
		c24 = m6.e24;
		c34 = m6.e34;

		B = GsPnt(c14, c24, c34);
		if (contains(A, B))
			reset();

		c14 = m7.e14;
		c24 = m7.e24;
		c34 = m7.e34;

		B = GsPnt(c14, c24, c34);
		if (contains(A, B))
			reset();

		c14 = m8.e14;
		c24 = m8.e24;
		c34 = m8.e34;

		B = GsPnt(c14, c24, c34);
		if (contains(A, B))
			reset();

		c14 = m9.e14;
		c24 = m9.e24;
		c34 = m9.e34;

		B = GsPnt(c14, c24, c34);
		if (contains(A, B))
			reset();

		c14 = m10.e14;
		c24 = m10.e24;
		c34 = m10.e34;

		B = GsPnt(c14, c24, c34);
		if (contains(A, B))
			reset();


		render(); // notify it needs redraw
		ws_check(); // redraw now
	} while (m.e24 > 0);
}

	
void MyViewer::firstperson() {

	if (on) {
		double lt = 0.0;
		double time = 0.0;
		double t0 = gs_time();
		do {
				
			lt = gs_time() - t0;
			camera().eye.y = 15.0f;

			camera().eye.z = 83.0f;

			//look in general distance but look away
			//camera().center.x = 2.0f;

			//tilt head left
			//camera().up.x += 0.01f;

			render();
			ws_check();
			message().setf("local time =%f", lt);
		} while (time < 3.0f);
	}
}


void MyViewer::move2() {
	SnTransform* t = torso->get<SnTransform>(0);
	SnTransform* t1 = torso->get<SnTransform>(1);
	SnTransform* t2 = torso->get<SnTransform>(2);
	SnTransform* t3 = torso->get<SnTransform>(3);
	SnTransform* t4 = torso->get<SnTransform>(4);
	SnTransform* t5 = torso->get<SnTransform>(5);
	SnTransform* t6 = torso->get<SnTransform>(6);

	GsMat m = t->get();
	GsMat m1 = t1->get();
	GsMat m2 = t2->get();
	GsMat m3 = t3->get();
	GsMat m4 = t4->get();
	GsMat m5 = t5->get();
	GsMat m6 = t6->get();

	if (front == true || back == true) {
		m.e34 = finc;
		t->set(m);
		m1.e34 = finc;
		t1->set(m1);
		m2.e34 = finc;
		t2->set(m2);
		m3.e34 = finc;
		t3->set(m3);
		m4.e34 = finc;
		t4->set(m4);
		m5.e34 = finc;
		t5->set(m5);
		m6.e34 = finc;
		t6->set(m6);
		render();
		if (step == true) {
			for (int i = 0; i < 4; i++) {
				leftL = true;
				run_animation(1);
				rightL = true;
				run_animation(-1);
			}
			step = false;
		}
		else {
			for (int i = 0; i < 4; i++) {
				leftL = true;
				run_animation(-1);
				rightL = true;
				run_animation(1);
			}
			step = true;
		}
		if (front == true)
			front = false;
		else
			back = false;
	}
	else if (left == true || right == true) {
		m.e14 = sinc;
		t->set(m);
		m1.e14 = sinc;
		t1->set(m1);
		m2.e14 = sinc;
		t2->set(m2);
		m3.e14 = sinc - .5f;
		t3->set(m3);
		m4.e14 = sinc + .5f;
		t4->set(m4);
		m5.e14 = sinc - 1;
		t5->set(m5);
		m6.e14 = sinc + 1;
		t6->set(m6);
		render();
		if (step == true) {
			for (int i = 0; i < 3; i++) {
				leftL = true; rightL = true;
				run_animation(-1);
			}
			step = false;
		}
		else {
			for (int i = 0; i < 3; i++) {
				leftL = true;  rightL = true;
				run_animation(1);
			}
			step = true;
		}
		if (left == true)
			left = false;
		else
			right = false;
	}

}
void MyViewer::move(SnGroup* limb, SnTransform* t, GsMat m, float n) {

	GsMat f;
	GsMat tr;
	GsMat rotate;
	GsMat origin;

	float theta = n * float(GS_2PI / 90);

	float e14 = m.e14;
	float e24 = m.e24;
	float e34 = m.e34;
	tr.translation(0, 0.5f, 0);
	e14 = -1 * e14;
	e24 = -1 * e24;
	e34 = -1 * e34;

	origin.translation(0, -0.5f, 0);
	//if (leftA == true || rightA == true) {
	if (side == true)
		rotate.rotz(theta);
	else
		rotate.rotx(theta);

	f = m * tr * rotate * origin;

	t->set(f);
}
void MyViewer::run_animation(float n)
{
	if (_animating) return; // avoid recursive calls
	_animating = true;

	if (leftL == true && rightL == true) {
		side = true;
		SnGroup* leftLeg = rootg()->get<SnGroup>(3);
		SnTransform* lLeg = leftLeg->get<SnTransform>(0);
		GsMat m = lLeg->get();
		move(leftLeg, lLeg, m, n);
		leftL = false;

		SnGroup* rightLeg = rootg()->get<SnGroup>(4);
		SnTransform* rLeg = rightLeg->get<SnTransform>(0);
		m = rLeg->get();
		move(rightLeg, rLeg, m, -n);
		rightL = false;
		side = false;
	}
	if (leftL == true) {
		SnGroup* leftLeg = rootg()->get<SnGroup>(3);
		SnTransform* lLeg = leftLeg->get<SnTransform>(0);
		GsMat m = lLeg->get();
		move(leftLeg, lLeg, m, n);
		leftL = false;
	}
	else if (rightL == true) {
		SnGroup* rightLeg = rootg()->get<SnGroup>(4);
		SnTransform* rLeg = rightLeg->get<SnTransform>(0);
		GsMat m = rLeg->get();
		move(rightLeg, rLeg, m, n);
		rightL = false;
	}
	else if (leftA == true) {
		SnGroup* leftArm = rootg()->get<SnGroup>(5);
		SnTransform* lArm = leftArm->get<SnTransform>(0);
		GsMat m = lArm->get();
		move(leftArm, lArm, m, n);
		leftA = false;
	}
	else if (rightA == true) {
		SnGroup* rightArm = rootg()->get<SnGroup>(6);
		SnTransform* rArm = rightArm->get<SnTransform>(0);
		GsMat m = rArm->get();
		move(rightArm, rArm, m, n);
		rightA = false;
	}
	render();
	//ws_check();
	_animating = false;
}


int MyViewer::handle_keyboard(const GsEvent& e) {
	int ret = WsViewer::handle_keyboard(e); // 1st let system check events
	if (ret) return ret;

	switch (e.key)
	{	case GsEvent::KeyEsc: gs_exit(); 
	return 1;
	//case 'n': { bool b = !_nbut->value(); _nbut->value(b); show_normals(b); return 1; }
			//default: gsout << "Key pressed: " << e.key << gsnl;
 
	case 'q': leftL = true; run_animation(-1); break;
	case 'a': leftL = true; run_animation(1); break;
	case 'w': rightL = true; run_animation(-1); break;
	case 's': rightL = true; run_animation(1); break;
	case 'e': leftA = true; run_animation(-1); break;
	case 'd': leftA = true; run_animation(1); break;
	case 'r': rightA = true; run_animation(-1); break;
	case 'f': rightA = true; run_animation(1); break;
	case 't': leftL = true; rightL = true; run_animation(-1); break;
	case 'g': leftL = true; rightL = true; run_animation(1); break;
	case 65361: sinc -= 0.45f; left = true; move2(); break;
	case 65362: finc -= 0.45f; front = true; move2(); break;
	case 65364: finc += 0.45f; back = true; move2(); break;
	case 65363: sinc += 0.45f; right = true; move2(); break;

		//first person
		//add later
		//case 'w': {
		//	camera().eye.y -= 0.9f;
		//	render();
		//	ws_check();
		//	return 1;

		//}
		//case 's': {

		//}
		//case 'a': {

		//}
		//case 'd': {

		//}
		//		//global movement
		//		//left arrow
		//case 65361: {
		//	persontranslation = h_head->mat();//mat is manipulator matrix
		//	xposition = 0.2f;
		//	persontranslation.e14 -= xposition;
		//	h_head->initial_mat(persontranslation);
		//	render();
		//	return 1;

		//}
				  //right arrow
				  //add later
		/*case 65363: {
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
				//render();
				//return 1; }
	
	//back
//add later
//case 65364: {
//	persontranslation = h_head->mat();
//	yposition = 0.35f;
//	persontranslation.e34 += yposition;
//	h_head->initial_mat(persontranslation);
//	render();
//	return 1;
//}

}
	return 0;
	}



//default: gsout << "Key pressed: " << e.key << gsnl;

int MyViewer::uievent(int e)
			{
		switch (e)
				{
				case EvNormals: show_normals(_nbut->value()); return 1;
				case EvAnimate: animatecars(); return 1;
				case EvCam: firstperson(); return 1;
				case EvExit: gs_exit();
				}
				return WsViewer::uievent(e);
			}

	
