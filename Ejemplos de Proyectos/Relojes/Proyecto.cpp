#include <osgViewer/Viewer> 
#include <osg/ShapeDrawable> 
#include <osg/MatrixTransform>
#include <osg/ApplicationUsage>
#include <osgViewer/ViewerEventHandlers>
#include <osgGA/StateSetManipulator>
#include <osg/Material>
#include <osg/StateSet>
#include <osg/Light>
#include <osg/LightSource>
#include <osg/AnimationPath>
#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <osg/Texture2D>
#include <osgDB/ReadFile>
#include <osg/Switch>
#include <osgGA/GUIEventHandler>
#include <osg/PositionAttitudeTransform>
#include <osg/Config>

osg::ref_ptr<osg::MatrixTransform> DigitoHora1;
osg::ref_ptr<osg::MatrixTransform> DigitoHora2;
osg::ref_ptr<osg::MatrixTransform> DigitoMinuto1;
osg::ref_ptr<osg::MatrixTransform> DigitoMinuto2;
osg::ref_ptr<osg::MatrixTransform> DigitoSegundo1;
osg::ref_ptr<osg::MatrixTransform> DigitoSegundo2;

osg::ref_ptr<osg::Switch> root;
bool switchModel = true;
int switcher = 0;

osg::Node* createDigit(float displacementH, float displacementV, int digit, bool big){
	// 0 Arriba, 1 Medio, 2 Abajo, 3 Arriba Derecha, 4 Abajo Derecha, 5 Arriba Izquierda, 6 Abajo Izquierda
	//Parámetros
	float p = 0.0, h = 0.0, size = 1.0;
	std::string chainSeg = ("0000000");

	if(!big) size = 0.5;
	switch(digit){
		case 0:
			chainSeg = ("023456");
			break;
		case 1:
			chainSeg = ("34");
			break;
		case 2:
			chainSeg = ("03162");
			break;
		case 3:
			chainSeg = ("03142");
			break;
		case 4:
			chainSeg = ("5134");
			break;
		case 5:
			chainSeg = ("05142");
			break;
		case 6:
			chainSeg = ("051426");
			break;
		case 7:
			chainSeg = ("034");
			break;
		case 8:
			chainSeg = ("0123456");
			break;
		case 9:
			chainSeg = ("05134");
			break;
	}

	//Grupo Dígito
	osg::ref_ptr<osg::MatrixTransform> Digito = new osg::MatrixTransform;
	//Dígito	
	for (int i = 0; i < chainSeg.size(); i++){
		switch (chainSeg.at(i)){
			case '0':
				p = 0.0;
				h = 1.0;
				break;
			case '1':
				p = 0.0;
				h = 0.0;
				break;
			case '2':
				p = 0.0;
				h = -1.0;
				break;
			case '3':
				p = 0.5;
				h = 0.5;
				break;
			case '4':
				p = 0.5;
				h = -0.5;
				break;
			case '5':
				p = -0.5;
				h =  0.5;
				break;
			case '6':
				p = -0.5;
				h = -0.5;
				break;
			default:
				break;
		}		
		//Segmento
		osg::Box *Segmento = new osg::Box(osg::Vec3f(0.0,0.0,0.0),1*size,.1*size,.3*size); 
		osg::ShapeDrawable *SegmentoDrawable = new osg::ShapeDrawable(Segmento); 
		osg::Geode *geodeSegmento = new osg::Geode();
		geodeSegmento->addDrawable(SegmentoDrawable);
		//Traslación		
		osg::MatrixTransform* transformacionSegmento1 = new osg::MatrixTransform();
		transformacionSegmento1->setMatrix(osg::Matrix::translate(p*size,0,h*size)); 
		if(chainSeg.at(i) == '5' || chainSeg.at(i) == '6' || chainSeg.at(i) == '3' || chainSeg.at(i) == '4'){
			//Rotación
			osg::MatrixTransform* transformacionSegmento2 = new osg::MatrixTransform(); 
			transformacionSegmento2->setMatrix(osg::Matrix::rotate(1.5707,0,1,0)); 
			transformacionSegmento2->addChild(geodeSegmento);
			transformacionSegmento1->addChild(transformacionSegmento2);
		}else{
			transformacionSegmento1->addChild(geodeSegmento);
		}
		//Colocación
		osg::MatrixTransform* transformacionSegmento11 = new osg::MatrixTransform();
		transformacionSegmento11->setMatrix(osg::Matrix::translate(displacementH,0,displacementV)); 
		transformacionSegmento11->addChild(transformacionSegmento1);
		//Añadir
		Digito->addChild(transformacionSegmento11);

	}

	return Digito.release();
}


osg::Node* createSeparator(float displacementH, float displacementV){
	//Grupo Separator
	osg::ref_ptr<osg::MatrixTransform> Separator = new osg::MatrixTransform;

	//Separator1
	osg::Box *Separator1 = new osg::Box(osg::Vec3f(0.0,0.0,0.0),.3,.1,.3); 
	osg::ShapeDrawable *Separator1Drawable = new osg::ShapeDrawable(Separator1); 
	osg::Geode *geodeSeparator1 = new osg::Geode();
	geodeSeparator1->addDrawable(Separator1Drawable);

	//Separator2
	osg::Box *Separator2 = new osg::Box(osg::Vec3f(0.0,0.0,0.0),.3,.1,.3); 
	osg::ShapeDrawable *Separator2Drawable = new osg::ShapeDrawable(Separator2); 
	osg::Geode *geodeSeparator2 = new osg::Geode();
	geodeSeparator2->addDrawable(Separator2Drawable);

	//Colocación1
	osg::MatrixTransform* transformacionSeparator1 = new osg::MatrixTransform();
	transformacionSeparator1->setMatrix(osg::Matrix::translate(displacementH,0,displacementV+0.5)); 
	transformacionSeparator1->addChild(geodeSeparator1);

	//Colocación2
	osg::MatrixTransform* transformacionSeparator2 = new osg::MatrixTransform();
	transformacionSeparator2->setMatrix(osg::Matrix::translate(displacementH,0,displacementV-0.5)); 
	transformacionSeparator2->addChild(geodeSeparator2);

	//Añadir
	Separator->addChild(transformacionSeparator1);
	Separator->addChild(transformacionSeparator2);

	//Material Separator
	osg::Material *materialSeparator = new osg::Material;
	materialSeparator->setSpecular( osg::Material::FRONT,osg::Vec4( 1,1,1,1 ) );
	materialSeparator->setAmbient( osg::Material::FRONT,osg::Vec4( 1,0,0,1 ) );
	materialSeparator->setDiffuse( osg::Material::FRONT,osg::Vec4( 1,0,0,1 ) );
	materialSeparator->setShininess( osg::Material::FRONT, 100 );
	//Estado Separator
	osg::StateSet *estadoSeparator = Separator->getOrCreateStateSet(); 
	estadoSeparator->setAttribute( materialSeparator );

	return Separator.release();
}
osg::Node* createNeedle( float w, float h, float depth, const osg::Vec4& color, float angle, double period ){
	//Vértices
	 osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array(5);
	(*vertices)[0].set(-h*0.5f, 0.0f,-w*0.1f );
	(*vertices)[1].set( h*0.5f, 0.0f,-w*0.1f );
	(*vertices)[2].set(-h*0.5f, 0.0f, w*0.8f );
	(*vertices)[3].set( h*0.5f, 0.0f, w*0.8f );
	(*vertices)[4].set( 0.0f, 0.0f, w*0.9f );

	//Normales y color
	osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array(1);
	(*normals)[0].set( 0.0f,-1.0f, 0.0f );
	osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array(1);
	(*colors)[0] = color;

	//Geometría
	osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
	geom->setVertexArray( vertices.get() );
	geom->setNormalArray( normals.get() );
	geom->setNormalBinding( osg::Geometry::BIND_OVERALL );
	geom->setColorArray( colors.get() );
	geom->setColorBinding( osg::Geometry::BIND_OVERALL );
	geom->addPrimitiveSet( new osg::DrawArrays( GL_TRIANGLE_STRIP, 0, 5) );
	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	geode->addDrawable( geom.get() );

	//Transformación y movimiento
	osg::ref_ptr<osg::MatrixTransform> trans = new osg::MatrixTransform;
	trans->addChild( geode.get() );

	osg::ref_ptr<osg::AnimationPath> clockPath = new osg::AnimationPath;
	clockPath->setLoopMode( osg::AnimationPath::LOOP );

	clockPath->insert( 0.0, osg::AnimationPath::ControlPoint(
	osg::Vec3(0.0f, depth, 0.0f), osg::Quat(angle, osg::Y_AXIS)) );

	clockPath->insert( period*0.5, osg::AnimationPath::ControlPoint(
	osg::Vec3(0.0f, depth, 0.0f), osg::Quat(angle+osg::PI,osg::Y_AXIS)) );

	clockPath->insert( period, osg::AnimationPath::ControlPoint(
	osg::Vec3(0.0f, depth, 0.0f), osg::Quat(angle+osg::PI*2.0f,	osg::Y_AXIS)) );
	
	//Callback
	osg::ref_ptr<osg::AnimationPathCallback> apcb =	new osg::AnimationPathCallback;
	apcb->setAnimationPath( clockPath.get() );
	trans->addUpdateCallback( apcb.get() );

	//Fin
	return trans.release();
}

osg::Node* createAnalog(){
	//Grupo Estructura
	osg::ref_ptr<osg::MatrixTransform> estructura = new osg::MatrixTransform;

	//Marco
	osg::Box *Frame = new osg::Box(osg::Vec3f(0,1,0),15,1,15); 
	osg::ShapeDrawable *FrameDrawable = new osg::ShapeDrawable(Frame); 
	osg::Geode *geodeFrame = new osg::Geode();
	geodeFrame->addDrawable(FrameDrawable);
	//Fin Marco

	//Material Marco
	osg::Material *materialFrame = new osg::Material;
	materialFrame->setSpecular( osg::Material::FRONT,osg::Vec4( 1,1,1,1 ) );
	materialFrame->setAmbient( osg::Material::FRONT,osg::Vec4( 1,.4,0,1 ) );
	materialFrame->setDiffuse( osg::Material::FRONT,osg::Vec4( 1,.4,0,1 ) );
	materialFrame->setShininess( osg::Material::FRONT, 100 );
	//Estado Marco
	osg::StateSet *estadoFrame = geodeFrame->getOrCreateStateSet(); 
	estadoFrame->setAttribute( materialFrame );
	
	//Grupo Esfera
	osg::Group *Esfera = new osg::Group();
	//Esfera
	osg::Cylinder *Radial = new osg::Cylinder(osg::Vec3f(0,0,-0.5),7,1); 
	osg::ShapeDrawable *RadialDrawable = new osg::ShapeDrawable(Radial); 
	osg::Geode *geodeRadial = new osg::Geode();
	geodeRadial->addDrawable(RadialDrawable);
	//Material Esfera
	osg::Material *materialEsfera = new osg::Material;
	materialEsfera->setSpecular( osg::Material::FRONT,osg::Vec4( 1,1,1,1 ) );
	materialEsfera->setAmbient( osg::Material::FRONT,osg::Vec4( 0,0,.27,1 ) );
	materialEsfera->setDiffuse( osg::Material::FRONT,osg::Vec4( 0,0,.27,1 ) );
	materialEsfera->setShininess( osg::Material::FRONT, 100 );
	//Estado Esfera
	osg::StateSet *estadoEsfera = geodeRadial->getOrCreateStateSet(); 
	estadoEsfera->setAttribute( materialEsfera );
	//Transformación Esfera
	osg::MatrixTransform* transformacionRadial =new osg::MatrixTransform(); 
	transformacionRadial->setMatrix(osg::Matrix::rotate(1.5707,1,0,0)); 
	transformacionRadial->addChild(geodeRadial); 
	//Añadir
	Esfera->addChild(transformacionRadial);
	//Fin Grupo Esfera

	//Grupo Manijas
	osg::Group *Manijas= new osg::Group();
	SYSTEMTIME st;
	GetLocalTime(&st);
	float hour_time = st.wHour, min_time = st.wMinute, sec_time = st.wSecond;	
	//Horas
	osg::Node* hour = createNeedle(3.9f, 0.3f,-0.02f,osg::Vec4(1.0f, 0.4f, 0.0f, 1.0f), osg::PI * hour_time / 6.0f, 3600*60.0);
	//Minutos
	osg::Node* minute = createNeedle(5.3f, 0.3f,-0.04f, osg::Vec4(1.0f, 0.4f, 0.0f, 1.0f), osg::PI * min_time/30.0f, 3600.0);
	//Segundos
	osg::Node* second = createNeedle(5.3f, 0.2f,-0.06f,osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f), osg::PI * sec_time/30.0f, 60.0);
	//Añadir
	Manijas->addChild( hour );
	Manijas->addChild( minute );
	Manijas->addChild( second );
	//Fin Grupo Manijas

	osg::TessellationHints* hints = new osg::TessellationHints;
	hints->setDetailRatio(0.4f);

	//Grupo Divisiones
	osg::Group *Divisiones = new osg::Group();
	//Divisiones
	float angle = 0.0;
	for (int i = 1; i <= 24; i++){	
		//Marker
		osg::Sphere *Marker = new osg::Sphere(osg::Vec3f(0,0,0),.1); 
		osg::ShapeDrawable *MarkerDrawable = new osg::ShapeDrawable(Marker,hints); 
		osg::Geode *geodeMarker = new osg::Geode();
		geodeMarker->addDrawable(MarkerDrawable);			
		//Transformacion Marker
		osg::MatrixTransform* transformacionMarker = new osg::MatrixTransform();
		transformacionMarker->setMatrix(osg::Matrix::translate(sin(2*3.1415/24*i)*4.75,0,cos(2*3.1415/24*i)*4.75)); 
		transformacionMarker->addChild(geodeMarker);
		//Transformación Number
		osg::MatrixTransform* transformacionNumber = new osg::MatrixTransform();
		transformacionNumber->setMatrix(osg::Matrix::translate(sin(2*3.1415/24*i)*6,0,cos(2*3.1415/24*i)*6)); 
		//Material Digit
		osg::Material *materialDigit = new osg::Material;
		materialDigit->setSpecular( osg::Material::FRONT,osg::Vec4( 1,1,1,1 ) );
		materialDigit->setAmbient( osg::Material::FRONT,osg::Vec4( 1,0,0,1 ) );
		materialDigit->setDiffuse( osg::Material::FRONT,osg::Vec4( 1,0,0,1 ) );
		materialDigit->setShininess( osg::Material::FRONT, 100 );
		//Estado Digit
		osg::StateSet *estadoDigit = transformacionNumber->getOrCreateStateSet(); 
		estadoDigit->setAttribute( materialDigit );
		if (i % 2 == 0 && i < 20){
			transformacionNumber->addChild(createDigit(0, 0, i/2, false));
			Divisiones->addChild(transformacionNumber);
		}else if (i == 20){
			transformacionNumber->addChild(createDigit(-.5, 0, 1, false));
			transformacionNumber->addChild(createDigit(0.5, 0, 0, false));
			Divisiones->addChild(transformacionNumber);
		}else if (i == 22){
			transformacionNumber->addChild(createDigit(-.5, 0, 1, false));
			transformacionNumber->addChild(createDigit(0.0, 0, 1, false));
			Divisiones->addChild(transformacionNumber);
		}else if (i == 24){
			transformacionNumber->addChild(createDigit(-.5, 0, 1, false));
			transformacionNumber->addChild(createDigit(0.5, 0, 2, false));
			Divisiones->addChild(transformacionNumber);
		}
		//Estado Marker
		osg::StateSet *estadoMarker = geodeMarker->getOrCreateStateSet(); 
		estadoMarker->setAttribute( materialFrame );
		//Fin Material Marker
		//Añadir
		Divisiones->addChild(transformacionMarker);
		
	}	
	//Fin Grupo Divisiones
	Esfera->addChild(Manijas);
	Esfera->addChild(Divisiones);
	estructura->addChild(Esfera);	
	estructura->addChild(geodeFrame);
		
	//Fin Estructura	
	return estructura.release();
}
class UpdateTime:public osg::NodeCallback
{
public:
	UpdateTime(float h)
	{
		displacementH = h;
	}

	virtual void operator()(osg::Node* node, osg::NodeVisitor* nv) 
	{
		SYSTEMTIME st;
		GetLocalTime(&st);
		float hour_time = st.wHour;
		float min_time = st.wMinute;
		float sec_time = st.wSecond; 
		osg::Group *nood=(osg::Group *)node;
		nood->removeChildren(0,nood->getNumChildren());
		int h = (int)displacementH;
		switch (h){
			case -2:
				nood->addChild(createDigit(-2.6, 0, floor(hour_time/10), true));
				break;
			case -1:
				nood->addChild(createDigit(-1, 0, hour_time-(floor(hour_time/10))*10, true));
				break;
			case 1:
				nood->addChild(createDigit(1, 0, floor(min_time/10), true));
				break;
			case 2:
				nood->addChild(createDigit(2.7, 0, min_time-(floor(min_time/10))*10, true));
				break;
			case 4:
				nood->addChild(createDigit(4.3, -.5, floor(sec_time/10), false));
				break;
			case 5:
				nood->addChild(createDigit(5, -.5, sec_time-(floor(sec_time/10))*10, false));
				break;
			default:
				break;
		}
		traverse(node,nv);
	}
private:
	float displacementH;
};
osg::Node* createDigital(osg::MatrixTransform *Hora1, osg::MatrixTransform *Hora2, osg::MatrixTransform *Min1, osg::MatrixTransform *Min2, osg::MatrixTransform *Sec1, osg::MatrixTransform *Sec2){
	//Grupo Digital
	osg::ref_ptr<osg::MatrixTransform> Digital = new osg::MatrixTransform;
	//Grupo Dígitos
	osg::Group *Digitos = new osg::Group();
	
	//Creación y Callback
	Hora1->addUpdateCallback(new UpdateTime(-2.6));
	Hora2->addUpdateCallback(new UpdateTime(-1));
	Min1->addUpdateCallback(new UpdateTime(1));
	Min2->addUpdateCallback(new UpdateTime(2.7));
	Sec1->addUpdateCallback(new UpdateTime(4.3));
	Sec2->addUpdateCallback(new UpdateTime(5));

	//Añadir
	Digitos->addChild( Hora1 );
	Digitos->addChild( Hora2 );
	Digitos->addChild(createSeparator(0.0, 0.0));
	Digitos->addChild( Min1 );
	Digitos->addChild( Min2 );
	Digitos->addChild( Sec1 );
	Digitos->addChild( Sec2 );
	//Fin Grupo Dígitos

	//Añadir
	Digital->addChild(Digitos);
	//Grupo Box
	osg::ref_ptr<osg::MatrixTransform> Box = new osg::MatrixTransform;

	//Body
	osg::Box *Body = new osg::Box(osg::Vec3f(0.0,0.0,0.0),9.5,2,3.5); 
	osg::ShapeDrawable *BodyDrawable = new osg::ShapeDrawable(Body); 
	osg::Geode *geodeBody = new osg::Geode();
	geodeBody->addDrawable(BodyDrawable);
	//Material Box
	osg::Material *materialBox = new osg::Material;
	materialBox->setSpecular( osg::Material::FRONT,osg::Vec4( 1,1,1,1 ) );
	materialBox->setAmbient( osg::Material::FRONT,osg::Vec4( 0,0,.27,1 ) );
	materialBox->setDiffuse( osg::Material::FRONT,osg::Vec4( 0,0,.27,1 ) );
	materialBox->setShininess( osg::Material::FRONT, 100 );
	//Estado Box
	osg::StateSet *estadoBox = geodeBody->getOrCreateStateSet(); 
	estadoBox->setAttribute( materialBox );
	//Frames
	osg::Box *Frame1 = new osg::Box(osg::Vec3f(0.0,0.0,0.0),9.1,.3,.2); 
	osg::ShapeDrawable *Frame1Drawable = new osg::ShapeDrawable(Frame1); 
	osg::Geode *geodeFrame1 = new osg::Geode();
	geodeFrame1->addDrawable(Frame1Drawable);
	osg::Box *Frame2 = new osg::Box(osg::Vec3f(0.0,0.0,0.0),.2,.3,3.5); 
	osg::ShapeDrawable *Frame2Drawable = new osg::ShapeDrawable(Frame2); 
	osg::Geode *geodeFrame2 = new osg::Geode();
	geodeFrame2->addDrawable(Frame2Drawable);
	//Material Frames
	osg::Material *materialFrames = new osg::Material;
	materialFrames->setSpecular( osg::Material::FRONT,osg::Vec4( 1,1,1,1 ) );
	materialFrames->setAmbient( osg::Material::FRONT,osg::Vec4( 1,.4,0,1 ) );
	materialFrames->setDiffuse( osg::Material::FRONT,osg::Vec4( 1,.4,0,1 ) );
	materialFrames->setShininess( osg::Material::FRONT, 100 );
	//Estado Frames
	osg::StateSet *estadoFrames1 = geodeFrame1->getOrCreateStateSet(); 
	estadoFrames1->setAttribute( materialFrames );
	osg::StateSet *estadoFrames2 = geodeFrame2->getOrCreateStateSet(); 
	estadoFrames2->setAttribute( materialFrames );
	//Traslaciones Up & Bot
	osg::MatrixTransform* transformacionFrame1 = new osg::MatrixTransform();
	transformacionFrame1->setMatrix(osg::Matrix::translate(1.3,-.1,1.65));
	osg::MatrixTransform* transformacionFrame1b = new osg::MatrixTransform();
	transformacionFrame1b->setMatrix(osg::Matrix::translate(1.3,-.1,-1.65));
	//Traslaciones Left & Right
	osg::MatrixTransform* transformacionFrame2 = new osg::MatrixTransform();
	transformacionFrame2->setMatrix(osg::Matrix::translate(5.95,-.1,0));
	osg::MatrixTransform* transformacionFrame2b = new osg::MatrixTransform();
	transformacionFrame2b->setMatrix(osg::Matrix::translate(-3.35,-.1,0));
	//Traslación Body		
	osg::MatrixTransform* transformacionBody = new osg::MatrixTransform();
	transformacionBody->setMatrix(osg::Matrix::translate(1.3,1.05,0));
	//Feet
	osg::TessellationHints* hints = new osg::TessellationHints;
	hints->setDetailRatio(0.4f);
	float x, y, z;
	for (int i = 0; i < 4; i++){
		switch (i){
			case 0:
				x = -3.0;
				y = 0.4;
				z = -1.75;
				break;
			case 1:
				x = -3.0;
				y = 1.6;
				z = -1.75;
				break;
			case 2:
				x = 5.6;
				y = 0.4;
				z = -1.75;
				break;
			case 3:
				x = 5.6;
				y = 1.6;
				z = -1.75;
				break;
			default:
				break;
		}
		osg::Sphere *Feet = new osg::Sphere(osg::Vec3f(x,y,z),.4); 
		osg::ShapeDrawable *FeetDrawable = new osg::ShapeDrawable(Feet,hints); 
		osg::Geode *geodeFeet = new osg::Geode();
		geodeFeet->addDrawable(FeetDrawable);
		osg::StateSet *estadoFeet = geodeFeet->getOrCreateStateSet(); 
		estadoFeet->setAttribute( materialFrames );
		Box->addChild(geodeFeet);
	}	

	//Añadir
	transformacionFrame1->addChild(geodeFrame1);
	transformacionFrame1b->addChild(geodeFrame1);
	transformacionFrame2->addChild(geodeFrame2);
	transformacionFrame2b->addChild(geodeFrame2);
	transformacionBody->addChild(geodeBody);
	Box->addChild(transformacionFrame1);
	Box->addChild(transformacionFrame1b);
	Box->addChild(transformacionFrame2);
	Box->addChild(transformacionFrame2b);
	Box->addChild(transformacionBody);
	
	//Fin Material Box
	Digital->addChild(Box);

	return Digital.release();
}



osg::Node* createJointClock(osg::MatrixTransform *Hora1, osg::MatrixTransform *Hora2, osg::MatrixTransform *Min1, osg::MatrixTransform *Min2, osg::MatrixTransform *Sec1, osg::MatrixTransform *Sec2){
	//Grupo Estructura
	osg::ref_ptr<osg::MatrixTransform> estructura = new osg::MatrixTransform;
	//Marco
	osg::Box *Frame = new osg::Box(osg::Vec3f(0,1,5),15,1,19); 
	osg::ShapeDrawable *FrameDrawable = new osg::ShapeDrawable(Frame); 
	osg::Geode *geodeFrame = new osg::Geode();
	geodeFrame->addDrawable(FrameDrawable);
	//Fin Marco
	//Material Marco
	osg::Material *materialFrame = new osg::Material;
	materialFrame->setSpecular( osg::Material::FRONT,osg::Vec4( 1,1,1,1 ) );
	materialFrame->setAmbient( osg::Material::FRONT,osg::Vec4( 1,.4,0,1 ) );
	materialFrame->setDiffuse( osg::Material::FRONT,osg::Vec4( 1,.4,0,1 ) );
	materialFrame->setShininess( osg::Material::FRONT, 100 );
	//Estado Marco
	osg::StateSet *estadoFrame = geodeFrame->getOrCreateStateSet(); 
	estadoFrame->setAttribute( materialFrame );
	
	//Grupo Esfera
	osg::Group *Esfera = new osg::Group();
	//Esfera
	osg::Cylinder *Radial = new osg::Cylinder(osg::Vec3f(0,0,-0.5),7,1); 
	osg::ShapeDrawable *RadialDrawable = new osg::ShapeDrawable(Radial); 
	osg::Geode *geodeRadial = new osg::Geode();
	geodeRadial->addDrawable(RadialDrawable);
	//Material Esfera
	osg::Material *materialEsfera = new osg::Material;
	materialEsfera->setSpecular( osg::Material::FRONT,osg::Vec4( 1,1,1,1 ) );
	materialEsfera->setAmbient( osg::Material::FRONT,osg::Vec4( 0,0,.27,1 ) );
	materialEsfera->setDiffuse( osg::Material::FRONT,osg::Vec4( 0,0,.27,1 ) );
	materialEsfera->setShininess( osg::Material::FRONT, 100 );
	//Estado Esfera
	osg::StateSet *estadoEsfera = geodeRadial->getOrCreateStateSet(); 
	estadoEsfera->setAttribute( materialEsfera );
	//Transformación Esfera
	osg::MatrixTransform* transformacionRadial =new osg::MatrixTransform(); 
	transformacionRadial->setMatrix(osg::Matrix::rotate(1.5707,1,0,0)); 
	transformacionRadial->addChild(geodeRadial); 
	//Añadir
	Esfera->addChild(transformacionRadial);
	//Fin Grupo Esfera

	//Grupo Manijas
	osg::Group *Manijas= new osg::Group();
	SYSTEMTIME st;
	GetLocalTime(&st);
	float hour_time = st.wHour, min_time = st.wMinute, sec_time = st.wSecond;	
	//Horas
	osg::Node* hour = createNeedle(3.9f, 0.3f,-0.02f,osg::Vec4(1.0f, 0.4f, 0.0f, 1.0f), osg::PI * hour_time / 6.0f, 3600*60.0);
	//Minutos
	osg::Node* minute = createNeedle(5.3f, 0.3f,-0.04f, osg::Vec4(1.0f, 0.4f, 0.0f, 1.0f), osg::PI * min_time/30.0f, 3600.0);
	//Segundos
	osg::Node* second = createNeedle(5.3f, 0.2f,-0.06f,osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f), osg::PI * sec_time/30.0f, 60.0);
	//Añadir
	Manijas->addChild( hour );
	Manijas->addChild( minute );
	Manijas->addChild( second );
	//Fin Grupo Manijas

	osg::TessellationHints* hints = new osg::TessellationHints;
	hints->setDetailRatio(0.4f);

	//Grupo Divisiones
	osg::Group *Divisiones = new osg::Group();
	//Divisiones
	float angle = 0.0;
	for (int i = 1; i <= 24; i++){	
		//Marker
		osg::Sphere *Marker = new osg::Sphere(osg::Vec3f(0,0,0),.1); 
		osg::ShapeDrawable *MarkerDrawable = new osg::ShapeDrawable(Marker,hints); 
		osg::Geode *geodeMarker = new osg::Geode();
		geodeMarker->addDrawable(MarkerDrawable);			
		//Transformacion Marker
		osg::MatrixTransform* transformacionMarker = new osg::MatrixTransform();
		transformacionMarker->setMatrix(osg::Matrix::translate(sin(2*3.1415/24*i)*4.75,0,cos(2*3.1415/24*i)*4.75)); 
		transformacionMarker->addChild(geodeMarker);
		//Transformación Number
		osg::MatrixTransform* transformacionNumber = new osg::MatrixTransform();
		transformacionNumber->setMatrix(osg::Matrix::translate(sin(2*3.1415/24*i)*6,0,cos(2*3.1415/24*i)*6)); 
		if (i % 2 == 0 && i < 20){
			transformacionNumber->addChild(createDigit(0, 0, i/2, false));
		}else if (i == 20){
			transformacionNumber->addChild(createDigit(-.5, 0, 1, false));
			transformacionNumber->addChild(createDigit(0.5, 0, 0, false));
		}else if (i == 22){
			transformacionNumber->addChild(createDigit(-.5, 0, 1, false));
			transformacionNumber->addChild(createDigit(0.0, 0, 1, false));
		}else if (i == 24){
			transformacionNumber->addChild(createDigit(-.5, 0, 1, false));
			transformacionNumber->addChild(createDigit(0.5, 0, 2, false));
		}
		//Material Digit
		osg::Material *materialDigit = new osg::Material;
		materialDigit->setSpecular( osg::Material::FRONT,osg::Vec4( 1,1,1,1 ) );
		materialDigit->setAmbient( osg::Material::FRONT,osg::Vec4( 1,0,0,1 ) );
		materialDigit->setDiffuse( osg::Material::FRONT,osg::Vec4( 1,0,0,1 ) );
		materialDigit->setShininess( osg::Material::FRONT, 100 );
		//Estado Digit
		osg::StateSet *estadoDigit = transformacionNumber->getOrCreateStateSet(); 
		estadoDigit->setAttribute( materialDigit );
		//Estado Marker
		osg::StateSet *estadoMarker = geodeMarker->getOrCreateStateSet(); 
		estadoMarker->setAttribute( materialFrame );
		//Fin Material Marker
		//Añadir
		Divisiones->addChild(transformacionMarker);
		Divisiones->addChild(transformacionNumber);
	}	

	//Grupo Digital
	osg::ref_ptr<osg::MatrixTransform> Digital = new osg::MatrixTransform;
	//Grupo Dígitos
	osg::Group *Digitos = new osg::Group();
	
	//Creación y Callback
	Hora1->addUpdateCallback(new UpdateTime(-2.6));
	Hora2->addUpdateCallback(new UpdateTime(-1));
	Min1->addUpdateCallback(new UpdateTime(1));
	Min2->addUpdateCallback(new UpdateTime(2.7));
	Sec1->addUpdateCallback(new UpdateTime(4.3));
	Sec2->addUpdateCallback(new UpdateTime(5));

	//Añadir
	Digitos->addChild( Hora1 );
	Digitos->addChild( Hora2 );
	Digitos->addChild(createSeparator(0.0, 0.0));
	Digitos->addChild( Min1 );
	Digitos->addChild( Min2 );
	Digitos->addChild( Sec1 );
	Digitos->addChild( Sec2 );
	//Fin Grupo Dígitos

	//Añadir
	Digital->addChild(Digitos);
	//Grupo Box
	osg::ref_ptr<osg::MatrixTransform> Box = new osg::MatrixTransform;

	//Frames
	osg::Box *Frame1 = new osg::Box(osg::Vec3f(0.0,0.0,0.0),9.1,.3,.2); 
	osg::ShapeDrawable *Frame1Drawable = new osg::ShapeDrawable(Frame1); 
	osg::Geode *geodeFrame1 = new osg::Geode();
	geodeFrame1->addDrawable(Frame1Drawable);
	osg::Box *Frame2 = new osg::Box(osg::Vec3f(0.0,0.0,0.0),.2,.3,3.5); 
	osg::ShapeDrawable *Frame2Drawable = new osg::ShapeDrawable(Frame2); 
	osg::Geode *geodeFrame2 = new osg::Geode();
	geodeFrame2->addDrawable(Frame2Drawable);
	//Material Frames
	osg::Material *materialFrames = new osg::Material;
	materialFrames->setSpecular( osg::Material::FRONT,osg::Vec4( 1,1,1,1 ) );
	materialFrames->setAmbient( osg::Material::FRONT,osg::Vec4( 1,.4,0,1 ) );
	materialFrames->setDiffuse( osg::Material::FRONT,osg::Vec4( 1,.4,0,1 ) );
	materialFrames->setShininess( osg::Material::FRONT, 100 );
	//Estado Frames
	osg::StateSet *estadoFrames1 = geodeFrame1->getOrCreateStateSet(); 
	estadoFrames1->setAttribute( materialFrames );
	osg::StateSet *estadoFrames2 = geodeFrame2->getOrCreateStateSet(); 
	estadoFrames2->setAttribute( materialFrames );
	//Traslaciones Up & Bot
	osg::MatrixTransform* transformacionFrame1 = new osg::MatrixTransform();
	transformacionFrame1->setMatrix(osg::Matrix::translate(1.3,-.1,1.65));
	osg::MatrixTransform* transformacionFrame1b = new osg::MatrixTransform();
	transformacionFrame1b->setMatrix(osg::Matrix::translate(1.3,-.1,-1.65));
	//Traslaciones Left & Right
	osg::MatrixTransform* transformacionFrame2 = new osg::MatrixTransform();
	transformacionFrame2->setMatrix(osg::Matrix::translate(5.95,-.1,0));
	osg::MatrixTransform* transformacionFrame2b = new osg::MatrixTransform();
	transformacionFrame2b->setMatrix(osg::Matrix::translate(-3.35,-.1,0));
	//Traslación Body		
	osg::MatrixTransform* transformacionBody = new osg::MatrixTransform();
	transformacionBody->setMatrix(osg::Matrix::translate(1.3,1.05,0));
	
	//Base
	osg::Box *Base = new osg::Box(osg::Vec3f(1.3,0.1,0),9.1,.1,3.1); 
	osg::ShapeDrawable *BaseDrawable = new osg::ShapeDrawable(Base); 
	osg::Geode *geodeBase = new osg::Geode();
	geodeBase->addDrawable(BaseDrawable);
	//Material Base
	osg::StateSet *estadoBase = geodeBase->getOrCreateStateSet(); 
	estadoBase->setAttribute( materialEsfera );

	osg::MatrixTransform* transformacionDigital = new osg::MatrixTransform();
	transformacionDigital->setMatrix(osg::Matrix::translate(0,-.1,7));
	transformacionDigital->addChild(Manijas);
	transformacionDigital->addChild(Divisiones);
	transformacionDigital->addChild(Esfera);

	osg::MatrixTransform* transformacionDigital2 = new osg::MatrixTransform();
	transformacionDigital2->setMatrix(osg::Matrix::translate(-1,0.4,-2.3));

	//Añadir
	transformacionFrame1->addChild(geodeFrame1);
	transformacionFrame1b->addChild(geodeFrame1);
	transformacionFrame2->addChild(geodeFrame2);
	transformacionFrame2b->addChild(geodeFrame2);
	Digital->addChild(transformacionFrame1);
	Digital->addChild(transformacionFrame1b);
	Digital->addChild(transformacionFrame2);
	Digital->addChild(transformacionFrame2b);
	Digital->addChild(geodeBase);
	transformacionDigital2->addChild(Digital);

	estructura->addChild(transformacionDigital);
	estructura->addChild(geodeFrame);
	estructura->addChild(transformacionDigital2);
		
	//Fin Estructura	
	return estructura.release();
}
class ModelController : public osgGA::GUIEventHandler
    {
    public:
       virtual bool handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter&);
       virtual void accept(osgGA::GUIEventHandlerVisitor& v)   { v.visit(*this); };
    };
 bool ModelController::handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa)
     {
       switch(ea.getEventType())
       {
       case(osgGA::GUIEventAdapter::KEYDOWN):
          {
             switch(ea.getKey())
             {
				case 'c': case 'C':
					if(switcher < 4){
						switcher++;
						root->setValue(switcher - 1, false);
						root->setValue(switcher, true);
					}else{
						switcher = 0;
						root->setValue(0, true);
						root->setValue(4, false);
					}
					break;
				 default:
					 break;
             } 
          }
       default:
          return false;
       }
    }

void main(){
	//Inicializaciones
	DigitoHora1 = new osg::MatrixTransform;
	DigitoHora2 = new osg::MatrixTransform;
	DigitoMinuto1 = new osg::MatrixTransform;
	DigitoMinuto2 = new osg::MatrixTransform;
	DigitoSegundo1 = new osg::MatrixTransform;
	DigitoSegundo2 = new osg::MatrixTransform;
	root = new osg::Switch;

	//Material Digit
	osg::Material *materialDigit = new osg::Material;
	materialDigit->setSpecular( osg::Material::FRONT,osg::Vec4( 1,1,1,1 ) );
	materialDigit->setAmbient( osg::Material::FRONT,osg::Vec4( 1,0,0,1 ) );
	materialDigit->setDiffuse( osg::Material::FRONT,osg::Vec4( 1,0,0,1 ) );
	materialDigit->setShininess( osg::Material::FRONT, 100 );

	//Estado Digit
	osg::StateSet *estadoDigit = DigitoHora1->getOrCreateStateSet(); 
	estadoDigit->setAttribute( materialDigit );
	osg::StateSet *estadoDigit1 = DigitoHora2->getOrCreateStateSet(); 
	estadoDigit1->setAttribute( materialDigit );
	osg::StateSet *estadoDigit2 = DigitoMinuto1->getOrCreateStateSet(); 
	estadoDigit2->setAttribute( materialDigit );
	osg::StateSet *estadoDigit3 = DigitoMinuto2->getOrCreateStateSet(); 
	estadoDigit3->setAttribute( materialDigit );
	osg::StateSet *estadoDigit4 = DigitoSegundo1->getOrCreateStateSet(); 
	estadoDigit4->setAttribute( materialDigit );
	osg::StateSet *estadoDigit5 = DigitoSegundo2->getOrCreateStateSet(); 
	estadoDigit5->setAttribute( materialDigit );
	//Fin Material Digit

	//Digital y Analógico
	osg::Node* analog = createAnalog();
	osg::Node* digital = createDigital(DigitoHora1, DigitoHora2, DigitoMinuto1, DigitoMinuto2, DigitoSegundo1, DigitoSegundo2);

	//Posicionamiento Digital
	osg::MatrixTransform* transformacionDigital = new osg::MatrixTransform();
	transformacionDigital->setMatrix(osg::Matrix::translate(10,45,14));
	transformacionDigital->addChild(digital);
	//Posicionamiento Analógico
	osg::MatrixTransform* transformacionAnalog = new osg::MatrixTransform();
	transformacionAnalog->setMatrix(osg::Matrix::translate(-33,60,25));
	transformacionAnalog->addChild(analog);

	//Posicionamiento Digital2
	osg::MatrixTransform* transformacionDigital2 = new osg::MatrixTransform();
	transformacionDigital2->setMatrix(osg::Matrix::translate(6,0,-5.5));
	transformacionDigital2->addChild(digital);
	//Posicionamiento Analógico2
	osg::MatrixTransform* transformacionAnalog2 = new osg::MatrixTransform();
	transformacionAnalog2->setMatrix(osg::Matrix::translate(-6,0,0));
	transformacionAnalog2->addChild(analog);

	//Escritorio 3DS
	osg::ref_ptr<osg::Node> tablenode (osgDB::readNodeFile("table_office/Table office N271114.3ds"));
	tablenode->getOrCreateStateSet()->setMode(GL_RESCALE_NORMAL,osg::StateAttribute::ON);
	osg::ref_ptr<osg::PositionAttitudeTransform> tablePAT (new osg::PositionAttitudeTransform);
	tablePAT->addChild(tablenode.get());
	tablePAT->setPosition(osg::Vec3(0,0,0));
	tablePAT->setScale(osg::Vec3(1.8,1.8,1.8));
	
	//Luz
	osg::Light *luz = new osg::Light();
	luz->setAmbient(osg::Vec4d(.6,.6,.6, 1));
	luz->setDiffuse(osg::Vec4d(.9,.9,.9, 1));
	luz->setSpecular(osg::Vec4d(1,1,1, 1));
	luz->setPosition(osg::Vec4d(-15, -15, -15, 1));
	//Fuente
	osg::LightSource *fuentedeluz= new osg::LightSource();
	fuentedeluz->setLight(luz);
	//Fin Luz

	//Manejador de eventos de teclado
	ModelController* keyboardHandler = new ModelController();

	//Grupos Raíz
	osg::Group *raiz= new osg::Group();
	osg::Group *bothClocksTable = new osg::Group();
	osg::Group *bothClocks = new osg::Group();

	//Añadir	
	raiz->addChild(fuentedeluz);
	bothClocksTable->addChild(transformacionAnalog);
	bothClocksTable->addChild(transformacionDigital);
	bothClocksTable->addChild(tablePAT);
	bothClocks->addChild(transformacionAnalog2);
	bothClocks->addChild(transformacionDigital2);
	root->addChild(bothClocksTable, true);
	root->addChild(bothClocks, false);
	root->addChild(createJointClock(DigitoHora1, DigitoHora2, DigitoMinuto1, DigitoMinuto2, DigitoSegundo1, DigitoSegundo2), false);
	root->addChild(analog, false);
	root->addChild(digital, false);
	raiz->addChild(root);
	osg::ref_ptr<ModelController> ctrler = new ModelController();
	//Fin Raíz

	osgViewer::Viewer viewer ; 
	viewer.addEventHandler(new osgViewer::StatsHandler); 
	viewer.addEventHandler(new osgViewer::WindowSizeHandler()); 
	viewer.addEventHandler(new osgViewer::LODScaleHandler()); 
	viewer.addEventHandler(new osgGA::StateSetManipulator( viewer.getCamera()->getOrCreateStateSet()) ); 
	viewer.addEventHandler(new osgViewer::HelpHandler()); 
	viewer.addEventHandler(keyboardHandler); 
	viewer.requestContinuousUpdate();
	viewer.setSceneData(raiz); 
	viewer.run(); 
}