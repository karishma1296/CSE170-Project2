# pragma once

# include <sig/sn_poly_editor.h>
# include <sig/sn_lines2.h>
#include<sig/sn_model.h>
# include <sigogl/ui_button.h>
# include <sigogl/ws_viewer.h>

// Viewer for this example:
class MyViewer : public WsViewer
{  protected :
	enum MenuEv { EvNormals, EvAnimate, EvExit };
	UiCheckButton* _nbut;
	int _torus_n;
	float _torus_R, _torus_r;
	GsMat t;
	GsMat persontranslation;
	int control;
	SnModel* _torus;
	bool _animating;
	//transm controls postition of row1 etc
	GsMat transm, transm2, transm3, transm4;
	GsPnt a, b, c, d;
	
   public :
	MyViewer ( int x, int y, int w, int h, const char* l );
	void build_ui ();
	void add_model ( SnShape* s, GsVec p );
	void build_scene ();
	void show_normals ( bool view );
	void run_animation ();
	void buildfirstrow();
	void buildsecondrow();
	void buildthirdrow();
	void buildfourthrow();
	void buildfifthrow();
	void buildsixthrow();

	virtual int handle_keyboard ( const GsEvent &e ) override;
	virtual int uievent ( int e ) override;
};

