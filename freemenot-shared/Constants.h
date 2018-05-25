#ifndef ConstantsH
#define ConstantsH
#include <string>
#include "MyExporter.h"
//---------------------------------------------------------------------------

#if __cplusplus <= 199711L
  //#error This library needs at least a C++11 compliant compiler
  #define nullptr NULL
#else
//  #define nullptr NULL
#endif


//typedef unsigned int u_int;
typedef unsigned int uint;

namespace dsl
{

using namespace std;
MyExport extern const string gEmptyString;
MyExport extern const string gCommaSpace;
MyExport extern const string gUndefinedString;
MyExport extern const string gNoneString;
MyExport extern const string gPluginFolder;

MyExport extern const char   gPathSeparator;
MyExport extern const char   gTab;
MyExport extern const char   gEOL;
MyExport extern const char   gComma;
MyExport extern const char*  gDoubleFormat;
MyExport extern const char*  gIntFormat;

MyExport extern const string gExplorerObjectString;
MyExport extern const string gMoleculixDB;
MyExport extern const string gLocalHost;
MyExport extern const double gMagicAngle;
MyExport extern const double gHBar;
MyExport extern const double gMynot;
MyExport extern const double gGammaCarbon;

//DSLEpsiolon is a arbitrary small number where we define a double being zero
MyExport extern const double gDSLEpsilon;

//#define ESC                     0x1b
MyExport extern const double gPi;
MyExport extern const double gTwoPi;
MyExport extern const double gPiBy2;
MyExport extern const double gPiBy4;

/////////////////////////////////////////////////////////////////////////////////////////////
enum DATA_FORMAT {  dfMoleculix, dfInteger, dfDouble, dfComplex,
                    dfFree,
                    dfCMX,
                    dfVAX_ASCII,
                    dfSimpson,
                    dfMXQET,
                    dfUW,
                    dfSpinVision,
                    dfWinSpin,
                    dfFELIX,
                    dfXYZ,
                    dfMolecule,
                    dfPDB,
                    dfCML,
                    dfText,
                    dfNone,  //Questionable..
                    dfUnknown,
};

enum CASE_SENSITIVITY {csCaseSensitive, csCaseInsensitive};
enum DIMENSION {Dim1 = 0, Dim2, Dim3};

enum FILE_FORMAT {ffASCII, ffBINARY, ffUnkown};
enum FILEINOUT {mtkIn=0, mtkOut};
enum IMAGEFORMAT {mtkJPEG = 0, mtkPNM, mtkPS, mtkBMP, mtkTIFF};
enum DATA_DIMENSION {rowDimension, colDimension};//current dimensions
enum DATAPROJECTION {rowProjection, colProjection};//current projections
enum FRAMETRANSFORMATION {PASToCrystal, PASToRotor, PASToLab, CrystalToRotor, CrystalToLab, RotorToLab};

enum RFCHANNEL {HChannel, CChannel, NChannel, PChannel};
enum POWDERTYPE {singleXtal, randomOrientations, gridOrientations, orientationsFromFile, unknownType};

//! \brief The atomic elements enums
enum ELEMENT
{
  eH=1,eHe, eLi, eBe, eB,  eC,  eN,  eO,  eF,  eNe, eNa, eMg, eAl, eSi, eP,
  eS,  eCl, eAr, eK,  eCa, eSc, eTi, eV,  eCr, eMn, eFe, eCo, eNi, eCu, eZn,
  eGa, eGe, eAs, eSe, eBr, eKr, eRb, eSr, eY,  eZr, eNb, eMo, eTc, eRu, eRh,
  ePd, eAg, eCd, eIn, eSn, eSb, eTe, eI,  eXe, eCs, eBa, eLa, eCe, ePr, eNd,
  ePm, eSm, eEu, eGd, eTb, eDy, eHo, eEr, eTm, eYb, eLu, eHf, eTa, eW,  eRe,
  eOs, eIr, ePt, eAu, eHg, eTl, ePb, eBi, ePo, eAt, eRn, eFr, eRa, eAc, eTh,
  ePa, eU,  eNp, ePu, eAm, eCm, eBk, eCf, eEs, eFm, eMd, eNo, eLr, eUndefined //( up to 105)
};


//Rendering, visual enums
enum LineRepresentationE {lrWire = 0, lrTube};
enum RENDERING_PRIMITIVE {rpPoint = 0, rpLine};
enum SHOWDATAPART {sdpReal = 0, sdpImag, sdpMag, sdpAll}; //Bits..
enum IconSize {SIZE_16x16, SIZE_24x24, SIZE_32x32};
}
#endif
