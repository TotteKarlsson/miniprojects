#pragma hdrstop
#include "Constants.h"
#include <float.h>
//---------------------------------------------------------------------------
namespace dsl
{

const string gEmptyString       = "";
const string gCommaSpace        = ", ";
const string gUndefinedString   = "undefined";
const string gNoneString        = "<none>";
const string gPluginFolder      = "Plugins";
const string gLocalHost	        = "127.0.0.1";

const char   gTab               = '\t';
const char   gEOL               = '\n';
const char   gComma             = ',';
const char*  gDoubleFormat 	    = "%f";
const char*  gIntFormat  	    = "%d";;

const double gMagicAngle        = 0.95531661812450929804896304631256498;
const double gHBar              = 1.054589e-34;
const double gMynot             = 1.25663706e-6;
const double gGammaCarbon       = 6.7283e7;

const double gPi                = 3.14159265358979323846;
const double gTwoPi             = 6.283185307;
const double gPiBy2             = 1.57079632679489661923;
const double gPiBy4             = 0.785398163397448309616;
const double gDSLEpsilon        = 10.*DBL_EPSILON;

#if defined(_WIN32)
    const char gPathSeparator   = '\\';
#elif defined(__unix__) || defined(__APPLE__)
    const char gPathSeparator   = '/';
#else
    const char gPathSeparator   = '/';
#endif

const string gExplorerObjectString = "ExplorerObject";
const string gMoleculixDB 			= "moleculix.db";



}
