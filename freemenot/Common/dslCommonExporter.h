#ifndef dsldslCommonExporterH
#define dsldslCommonExporterH

#if defined (_WIN32)
	#if defined(DSL_STATIC)
		#define DSL_COMMON
	#else
		#if defined(EXPORT_COMMON)
			#define DSL_COMMON __declspec(dllexport)
		#else
			#define DSL_COMMON __declspec(dllimport)
		#endif
	#endif
#else
	#define DSL_COMMON
#endif


#endif
