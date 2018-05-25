#ifndef FreeMeNotExporterH
#define FreeMeNotExporterH

#if defined (_WIN32)
    #if defined(EXPORT_DLL)
        #define MyExport __declspec(dllexport)
    #else
        #define MyExport __declspec(dllimport)
    #endif
#else
	#define MyExport
#endif

#endif
