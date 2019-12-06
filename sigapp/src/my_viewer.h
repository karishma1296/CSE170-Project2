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
	
   public :
	MyViewer ( int x, int y, int w, int h, const char* l );
	void build_ui ();
	void add_model ( SnShape* s, GsVec p );
	void build_scene ();
	void setrans();
	//GsCamera& camera(bool);
	//void camera();
	//void camerapersp(bool); 
	//GsCamera& camera();
	//void make_torus();
	//void texturize(GsModel* m);
	void show_normals ( bool view );
	void run_animation ();
	virtual int handle_keyboard ( const GsEvent &e ) override;
	virtual int uievent ( int e ) override;
};

