// Folgender ifdef-Block ist die Standardmethode zum Erstellen von Makros, die das Exportieren 
// aus einer DLL vereinfachen. Alle Dateien in dieser DLL werden mit dem CHROCODILEDEMOLIB_EXPORTS-Symbol
// kompiliert, das in der Befehlszeile definiert wurde. Das Symbol darf nicht für ein Projekt definiert werden,
// das diese DLL verwendet. Alle anderen Projekte, deren Quelldateien diese Datei beinhalten, erkennen 
// CHROCODILEDEMOLIB_API-Funktionen als aus einer DLL importiert, während die DLL
// mit diesem Makro definierte Symbole als exportiert ansieht.
#ifdef CHROCODILEDEMOLIB_EXPORTS
#define CHROCODILEDEMOLIB_API extern "C" __declspec(dllexport)
#else
#define CHROCODILEDEMOLIB_API extern "C" __declspec(dllimport)
#endif

typedef unsigned int u32;


static const int Raw_Spectrum = 0;
static const int Confocal_Spectrum = 1;
static const int FT_Spectrum = 2;

static const int DeviceMode_FreeRun = 0;
static const int DeviceMode_WaitTrigger = 1;
static const int DeviceMode_TriggerEach = 2;


static const int Encoder_Source_PreloadTrigger_A0 = 0;
static const int Encoder_Source_PreloadTrigger_B0 = 1;
static const int Encoder_Source_PreloadTrigger_A1 = 2;
static const int Encoder_Source_PreloadTrigger_B1 = 3;
static const int Encoder_Source_PreloadTrigger_A2 = 4;
static const int Encoder_Source_PreloadTrigger_B2 = 5;
static const int Encoder_Source_PreloadTrigger_A3 = 6;
static const int Encoder_Source_PreloadTrigger_B3 = 7;
static const int Encoder_Source_PreloadTrigger_A4 = 8;
static const int Encoder_Source_PreloadTrigger_B4 = 9;
static const int Encoder_Source_PreloadTrigger_SyncIn = 10;
static const int Encoder_Source_Quadrature = 15;
static const int Encoder_PreloadTrigger_Immediate = 15;

static const int Encoder_Preload_Once = 0;
static const int Encoder_Preload_Eachtime = 1;
static const int Encoder_Preload_Trigger_RisingEdge = 0;
static const int Encoder_Preload_Trigger_FallingEdge = 2;
static const int Encoder_Preload_Trigger_OnEdge = 0;
static const int Encoder_Preload_Trigger_OnLevel = 4;
static const int Encoder_Preload_Active = 8;



//error message of last error
CHROCODILEDEMOLIB_API const char * LastError(void);
CHROCODILEDEMOLIB_API const char * LastDeviceError(u32 _hConnection);

//connect to CHRocodile Device. Device type: 0, first generation CHRocodile device; 1, CHR² device; 2, CLS/MPS device
CHROCODILEDEMOLIB_API int OpenConnection(const char * _strConnectionInfo, int _nDeviceType, int * _pHandle);
//disconnect
CHROCODILEDEMOLIB_API int CloseConnection(u32 _hConnection);
CHROCODILEDEMOLIB_API int GetConnectionInfo(u32 _hConnection,  const char ** _strConnectionInfo);
CHROCODILEDEMOLIB_API int GetDeviceType(u32 _hConnection);

//read the next sample from device
CHROCODILEDEMOLIB_API int GetNextSample(u32 _hConnection, double ** _ppData, int * _pnNumberOfSignals);
CHROCODILEDEMOLIB_API int GetNextSampleMultiChannel(u32 _hConnection, double ** _ppData, int * _pnNumberOfSignals, int * _pnNumberOfGlobalSigs, int * _pnNumberOfChannels);
//read the newest sample from device, read pointer will automatically move to the newest sample.....
CHROCODILEDEMOLIB_API int GetLastSample(u32 _hConnection, double ** _ppData, int * _pnNumberOfSignals);
CHROCODILEDEMOLIB_API int GetLastSampleMultiChannel(u32 _hConnection, double ** _ppData, int * _pnNumberOfSignals, int * _pnNumberOfGlobalSigs, int * _pnNumberOfChannels);

//send command to device and wait for response
CHROCODILEDEMOLIB_API int ExecCommand(u32 _hConnection, const char * _pstrCmd, const char ** _pstrResponse);

//move the read pointer to last valid stream position
CHROCODILEDEMOLIB_API int FlushInputBuffer(u32 _hConnection);

//get the counter which indicates the number of data stream failing 
CHROCODILEDEMOLIB_API int GetStreamFailCounter(u32 _hConnection);

//set reader to the mode (auto buffer save mode), which automatically save the incoming data to the target buffer..
CHROCODILEDEMOLIB_API int SetToAutoBufferSave(u32 _hConnection, double * _pBuffer, int _nSampleNr);
CHROCODILEDEMOLIB_API int SetToAutoBufferSaveWithSizeCheck(u32 _hConnection, double * _pBuffer, int _nSampleNr, int * _pBufferSize);
//get the sample number, which has been saved to the buffer in auto buffer save mode
CHROCODILEDEMOLIB_API int GetAutoBufferSavedSampleNr(u32 _hConnection);

//set reader to normal mode...
CHROCODILEDEMOLIB_API int ClearAutoBufferSave(u32 _hConnection);

//check whether reader still in the auto. save mode
CHROCODILEDEMOLIB_API int IsAutoBufferSave(u32 _hConnection);


//set output signal by device
CHROCODILEDEMOLIB_API int SetOutputSignals(u32 _hConnection, int * _anSignals, int _nSignalsCount);
CHROCODILEDEMOLIB_API int GetDeviceOutputSignalIDs(u32 _hConnection, int ** _pSignalIDbuffer, int * _pSignalNr);
CHROCODILEDEMOLIB_API int GetDLLOutputSignalIDs(u32 _hConnection, int ** _pSignalIDbuffer, int * _pSignalNr);
CHROCODILEDEMOLIB_API int GetDeviceOutputSignalFormatIndex(u32 _hConnection, int * _pSignalFormatIdx);
CHROCODILEDEMOLIB_API int GetDeviceChannelNumber(u32 _hConnection);




CHROCODILEDEMOLIB_API int SetMeasuringMode (u32 _hConnection, int _nMode);
CHROCODILEDEMOLIB_API int GetFullScale (u32 _hConnection, int * _pnFullScale);
//CHROCODILEDEMOLIB_API int SetScanRateIdx (u32 _hConnection, int _nIndex);
CHROCODILEDEMOLIB_API int SetScanRate (u32 _hConnection, float _nScanRate);
CHROCODILEDEMOLIB_API int SetDataAverage (u32 _hConnection, int _nAVD);
CHROCODILEDEMOLIB_API int SetSpectrumAverage (u32 _hConnection, int _nAVS);
CHROCODILEDEMOLIB_API int SetRefractiveIndex (u32 _hConnection, float _nRefIdx);
CHROCODILEDEMOLIB_API int SetABBENumber(u32 _hConnection, float _nABBE);
CHROCODILEDEMOLIB_API int SetLampIntensity (u32 _hConnection, float _nIntensity);
CHROCODILEDEMOLIB_API int SetLightSouceAutoAdapt (u32 _hConnection, int _bAuto, float _nLevel);
CHROCODILEDEMOLIB_API int SetOpticalProbe (u32 _hConnection, int _nIndex);
CHROCODILEDEMOLIB_API int SetRefractiveIndexTable (u32 _hConnection, int _nIndex);
CHROCODILEDEMOLIB_API int SetConfocalDetectionThreshold (u32 _hConnection, int _nThreshold);
CHROCODILEDEMOLIB_API int SetInterQualityThreshold (u32 _hConnection, int _nThreshold);
CHROCODILEDEMOLIB_API int SetDetectionWindowActive (u32 _hConnection, int _bActive);
//valid for CHR²/MPS/CLS device
CHROCODILEDEMOLIB_API int SetDetectionWindow (u32 _hConnection, float * _anDWs, int _nWindowNr);
//valid for first generation CHRocodile device
CHROCODILEDEMOLIB_API int SetLimit (u32 _hConnection, int _bLeft, float _nLimit);
CHROCODILEDEMOLIB_API int SetAnalogOutput (u32 _hConnection, int _nIndex, int _nSignalID, float _nMin, float _nMax);
//valid for CHR²/MPS/CLS device
CHROCODILEDEMOLIB_API int SetAnalogOutputExtended (u32 _hConnection, int _nIndex, int _nSignalID, 
		float _nMin, float _nMax, float _nVolMin, float _nVolMax, float _nVolInvalid);
//valid for CHR²/MPS/CLS device
CHROCODILEDEMOLIB_API int SetMedian(u32 _hConnection, int _nMedianWidth, float _nPercentile);
//valid for CHR²/MPS/CLS device
CHROCODILEDEMOLIB_API int SetNumberOfPeaks(u32 _hConnection, int _nPeakNum);
//valid for CHR²/MPS/CLS device
CHROCODILEDEMOLIB_API int SetPeakOrdering(u32 _hConnection, int _nPeakOrdering);

//encoder counter related function
CHROCODILEDEMOLIB_API int SetEncoderCounter(u32 _hConnection, int _nAxis, int _nPosition);
CHROCODILEDEMOLIB_API int SetEncoderCounterSource(u32 _hConnection, int _nAxis, int _nSource);
CHROCODILEDEMOLIB_API int SetEncoderPreloadFunction(u32 _hConnection, int _nAxis, int _nPreloadValue, int _nPreloadFunctionSetting);
CHROCODILEDEMOLIB_API int SetEncoderPreloadFunctionExtended(u32 _hConnection, int _nAxis, int _nPreloadValue, int _nPreloadFunctionSetting, int _nTriggerSource);
//encoder trigger related function
CHROCODILEDEMOLIB_API int SetEncoderTriggerProperty(u32 _hConnection, int _nEncoderAxis, int _nStartPos, int _nStopPos, float _nInterval,
	bool _bTriggerOnReturnMove);
CHROCODILEDEMOLIB_API int SetEncoderTriggerEnabled(u32 _hConnection, bool _bEnabled);
CHROCODILEDEMOLIB_API int SetDeviceTriggerMode(u32 _hConnection, int _nTriggerMode);


CHROCODILEDEMOLIB_API int DarkReference(u32 _hConnection);
CHROCODILEDEMOLIB_API int StartDataStream(u32 _hConnection);
CHROCODILEDEMOLIB_API int StopDataStream(u32 _hConnection);

//download spectrum, spectrum type: 0, raw spectrum; 1, processed spectrum in confocal mode; 2, FT spectrum
//valid for first generation CHRocodile device and CHRocodile² device
CHROCODILEDEMOLIB_API int DownloadDeviceSpectrum(u32 _hConnection, int _nSpecType, short ** _pSpectrumBuffer, int * _pSpectrumLength);
//valid for MPS/CLS device
CHROCODILEDEMOLIB_API int  DownloadDeviceSpectrumsMultiChannel(u32 _hConnection, int _nSpecType, int _nStartChannelIdx, int _nChannelNumber,
	short ** _pSpectrumBuffer, int * _pSingleSpectrumLength);
CHROCODILEDEMOLIB_API int  DownloadDeviceSpectrumMultiChannel(u32 _hConnection, int _nSpecType, int _nChannelIdx, 
		short ** _pSpectrumBuffer, int * _pSpectrumLength);
CHROCODILEDEMOLIB_API int DownloadCurrentCalibrationTable(u32 _hConnection, char ** _pTable, int * _nTableLength);
CHROCODILEDEMOLIB_API int DownloadWaveLengthTable(u32 _hConnection, char ** _pTable, int * _nTableLength);

//CLS profile interpolation
CHROCODILEDEMOLIB_API int SetMultiChannelProfileInterpolation(u32 _hConnection, int _nMaxHoleSize);

CHROCODILEDEMOLIB_API int isClientBehind(u32 _hConnection);

void CloseAllConnections();