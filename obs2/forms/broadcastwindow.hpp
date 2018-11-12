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

class BroadcastWindow : public IMainWindow, public QMainWindow {
	Q_OBJECT
private:
	volatile bool previewProgramMode = false;
	OBSWeakSource programScene;
	OBSService service;
	bool previewEnabled = true;
	long disableSaving = 1;
	float previewScale = 0.0f;
	SPreviewInfo previewInfo;
	ConfigFile    basicConfig;
	std::unique_ptr<BasicOutputHandler> outputHandler;
	int disableOutputsRef = 0;

public:
	BroadcastWindow(QWidget *parent);
	virtual ~BroadcastWindow() {}

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

private:
	std::unique_ptr<Ui::BroadcastWindow> ui;
};

#endif

