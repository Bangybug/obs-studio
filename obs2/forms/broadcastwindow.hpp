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

class BroadcastWindow : public IMainWindow, public QMainWindow {
	Q_OBJECT
private:
	volatile bool previewProgramMode = false;
	OBSWeakSource programScene;
	OBSService service;
	bool previewEnabled = true;
	long disableSaving = 1;
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

	// TODO TransitionToScene
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

	void SaveProject();

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

	void TransitionToScene(OBSScene scene, bool force = false,
		bool direct = false);
	void TransitionToScene(OBSSource scene, bool force = false,
		bool direct = false, bool quickTransition = false);
	void SetCurrentScene(OBSSource scene, bool force = false,
		bool direct = false);


private:
	std::unique_ptr<Ui::BroadcastWindow> ui;
};

#endif

