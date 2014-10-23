// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the DUMPWRITETOOL_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// DUMPWRITETOOL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef DUMPWRITETOOL_EXPORTS
#define DUMPWRITETOOL_API __declspec(dllexport)
#else
#define DUMPWRITETOOL_API __declspec(dllimport)
#endif

// This class is exported from the dumpwritetool.dll
class DUMPWRITETOOL_API Cdumpwritetool {
public:
	Cdumpwritetool(void);
	// TODO: add your methods here.
};

extern DUMPWRITETOOL_API int ndumpwritetool;

DUMPWRITETOOL_API int fndumpwritetool(void);
