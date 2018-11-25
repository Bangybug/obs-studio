#ifndef _BROADCASTWINDOW_H
#define _BROADCASTWINDOW_H

#include <qmainwindow.h>
#include <memory>
#include "ui-broadcastwindow.hpp"
#include "../hack/imainwindow.h"
#include <util/threading.h>
#include <obs.hpp>
#include <obs-frontend-api.h>
#include <window-basic-main-outputs.hpp>
#include <util/util.hpp>
#include <obs-frontend-internal.hpp>
#include <window-main.hpp>

#define DESKTOP_AUDIO_1 Str("DesktopAudioDevice1")
#define DESKTOP_AUDIO_2 Str("DesktopAudioDevice2")
#define AUX_AUDIO_1     Str("AuxAudioDevice1")
#define AUX_AUDIO_2     Str("AuxAudioDevice2")
#define AUX_AUDIO_3     Str("AuxAudioDevice3")
#define AUX_AUDIO_4     Str("AuxAudioDevice4")

#define SIMPLE_ENCODER_X264                    "x264"
#define SIMPLE_ENCODER_X264_LOWCPU             "x264_lowcpu"
#define SIMPLE_ENCODER_QSV                     "qsv"
#define SIMPLE_ENCODER_NVENC                   "nvenc"
#define SIMPLE_ENCODER_AMD                     "amd"

#define PREVIEW_EDGE_SIZE 10

class VolControl;


class BroadcastWindow : public IMainWindow {
	Q_OBJECT
private:
	volatile bool previewProgramMode = false;
	OBSWeakSource programScene;
	OBSService service;
	bool previewEnabled = true;
	long disableSaving = 1;
	float previewScale = 0.0f;
	SPreviewInfo previewInfo;
	ConfigFile basicConfig;
	std::unique_ptr<BasicOutputHandler> outputHandler;
	int disableOutputsRef = 0;
	obs_frontend_callbacks *api = nullptr;
	std::vector<VolControl*> volumes;
	std::vector<OBSSignal> signalHandlers;
	obs_source_t *fadeTransition;

public:
	BroadcastWindow(QWidget *parent);
	virtual ~BroadcastWindow() {}

	void OBSInit();

	int getSceneCount();

	OBSScene getScene(int index);

	inline bool IsPreviewProgramMode() const
	{
		return os_atomic_load_bool(&previewProgramMode);
	}

	inline QMainWindow* getWindow()
	{
		return this;
	}

	// TransitionToScene
	// SetCurrentScene
	// SetTransition
	// AddSceneCollection
	// StartStreaming
	// StopStreaming
	// StartRecording
	// StopRecording
	// StartReplayBuffer
	// ReplayBufferSave
	// StopReplayBuffer
	// DeferSaveBegin
	// DeferSaveEnd
	// SetCurrentScene
	// StreamDelayStarting
	// StreamStopping
	// StreamDelayStopping
	// StreamingStart
	// StreamingStop
	// RecordingStart
	// RecordingStop
	// RecordStopping
	// ReplayBufferStart
	// ReplayBufferStop
	// ReplayBufferStopping

	OBSWeakSource getProgramScene();
	OBSSource GetCurrentSceneSource();
	OBSScene GetCurrentScene();

	int getTransitionCount();
	OBSSource getTransition(int index);
	OBSSource GetCurrentTransition();

	void openSceneCollection(const char* collection);
	void setCurrentProfile(const char* profile);

	bool isStreamingActive();
	bool isRecordingActive();

	bool isReplayBufferActive();

	void* addToolsMenuAction(const char *name);
	void addToolsMenuItem(const char *name, obs_frontend_cb callback, void *private_data);

	std::unique_ptr<BasicOutputHandler>& getOutputHandler();

	config_t *getProfileConfig();

	void SetService(obs_service_t *service);

	obs_service_t *GetService();

	void SaveService();

	void SetPreviewProgramMode(bool enabled);

	bool isPreviewEnabled();

	void EnablePreviewDisplay(bool enabled);

	inline bool SavingDisabled() const
	{
		return disableSaving;
	}

	OBSSource GetProgramSource();

	float getPreviewScale();

	SPreviewInfo& getPreviewInfo();

	config_t *Config() const;

	void SysTrayNotify(const QString &text, QSystemTrayIcon::MessageIcon n);

public slots:

	void DeferSaveBegin();
	void DeferSaveEnd();

	void StartStreaming();
	void StopStreaming();
	//void ForceStopStreaming();

	void StreamDelayStarting(int sec);
	void StreamDelayStopping(int sec);

	void StreamingStart();
	void StreamStopping();
	void StreamingStop(int errorcode, QString last_error);

	void StartRecording();
	void StopRecording();

	void RecordingStart();
	void RecordStopping();
	void RecordingStop(int code);

	void StartReplayBuffer();
	void StopReplayBuffer();

	void ReplayBufferStart();
	void ReplayBufferSave();
	void ReplayBufferStopping();
	void ReplayBufferStop(int code);

	//void SaveProjectDeferred();
	void SaveProject();

	void SetTransition(OBSSource transition);
	void TransitionToScene(OBSScene scene, bool force = false,
		bool direct = false);
	void TransitionToScene(OBSSource scene, bool force = false,
		bool direct = false, bool quickTransition = false);
	void SetCurrentScene(OBSSource scene, bool force = false,
		bool direct = false);

	bool AddSceneCollection(
		bool create_new,
		const QString &name = QString());

	void ResetOutputs();


	int GetProfilePath(char *path, size_t size, const char *file) const;

	bool InitBasicConfig();
	bool InitBasicConfigDefaults();

	bool ResetAudio();
	int ResetVideo();

	void AddScene(OBSSource source);
	void RemoveScene(OBSSource source);
	void ActivateAudioSource(OBSSource source);
	void DeactivateAudioSource(OBSSource source);

private:
	void GetConfigFPS(uint32_t &num, uint32_t &den) const;
	void GetFPSInteger(uint32_t &num, uint32_t &den) const;
	void GetFPSFraction(uint32_t &num, uint32_t &den) const;
	void GetFPSNanoseconds(uint32_t &num, uint32_t &den) const;
	void GetFPSCommon(uint32_t &num, uint32_t &den) const;

	void ResetAudioDevice(const char *sourceId, const char *deviceId,const char *deviceDesc, int channel);

	static void SourceCreated(void *data, calldata_t *params);
	static void SourceRemoved(void *data, calldata_t *params);
	static void SourceActivated(void *data, calldata_t *params);
	static void SourceDeactivated(void *data, calldata_t *params);

	void SetCurrentScene(obs_scene_t *scene, bool force = false, bool direct = false);

	void ResizePreview(uint32_t cx, uint32_t cy);
	void Load(const char *file);

	void InitTransition(obs_source_t *transition);
	void InitDefaultTransitions();
	void ClearSceneData();
	void CreateDefaultScene(bool firstStart);
	void CreateFirstRunSources();

	void InitOBSCallbacks();

private:
	std::unique_ptr<Ui::BroadcastWindow> ui;
};

#endif

