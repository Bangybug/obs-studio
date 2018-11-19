#pragma once

#include <obs.hpp>
#include <obs-frontend-api.h>
#include <window-basic-main-outputs.hpp>
#include <QSystemTrayIcon>
#include <window-main.hpp>

typedef struct PreviewInfo {
	float scale = 0.0f;
	int x = 0, y = 0;
	gs_vertbuffer_t *boxLeft = nullptr;
	gs_vertbuffer_t *boxTop = nullptr;
	gs_vertbuffer_t *boxRight = nullptr;
	gs_vertbuffer_t *boxBottom = nullptr;
	gs_vertbuffer_t *box = nullptr;
	gs_vertbuffer_t *circle = nullptr;
} SPreviewInfo;


class IMainWindow : public OBSMainWindow
{
public:
	inline IMainWindow(QWidget *parent) : OBSMainWindow(parent) {}

	virtual int getSceneCount() = 0;

	virtual OBSScene getScene(int index) = 0;

	virtual bool IsPreviewProgramMode() const = 0;

	virtual QMainWindow* getWindow() = 0;

	virtual OBSSource GetProgramSource() = 0;

	virtual OBSWeakSource getProgramScene() = 0;

	virtual OBSScene GetCurrentScene()=0;

	virtual OBSSource GetCurrentSceneSource() = 0;

	virtual int getTransitionCount() = 0;

	virtual OBSSource getTransition(int index) = 0;

	virtual OBSSource GetCurrentTransition() = 0;

	virtual void openSceneCollection(const char* collection) = 0;

	virtual void setCurrentProfile(const char* profile) = 0;

	virtual bool isStreamingActive() = 0;

	virtual bool isRecordingActive() = 0;

	virtual bool isReplayBufferActive() = 0;

	virtual void* addToolsMenuAction(const char *name) = 0;

	virtual void addToolsMenuItem(const char *name, obs_frontend_cb callback, void *private_data) = 0;

	virtual std::unique_ptr<BasicOutputHandler>& getOutputHandler() = 0;

	virtual config_t *getProfileConfig() = 0;

	virtual void SaveProject() =0;

	virtual void SetService(obs_service_t *service)=0;

	virtual obs_service_t *GetService()=0;

	virtual void SaveService() = 0;

	virtual void SetPreviewProgramMode(bool enabled)=0;

	virtual bool isPreviewEnabled()=0;

	virtual void EnablePreviewDisplay(bool enabled)=0;

	virtual bool SavingDisabled() const =0;

	virtual void TransitionToScene(OBSScene scene, bool force = false,
		bool direct = false) = 0;

	virtual void TransitionToScene(OBSSource scene, bool force = false,
		bool direct = false, bool quickTransition = false) = 0;

	virtual void SetCurrentScene(OBSSource scene, bool force = false,
		bool direct = false) = 0;

	virtual float getPreviewScale()=0;

	virtual SPreviewInfo& getPreviewInfo()=0;

	virtual config_t *Config() const =0;

	virtual void SysTrayNotify(const QString &text, QSystemTrayIcon::MessageIcon n)=0;

	virtual void OBSInit()=0;

	virtual int GetProfilePath(char *path, size_t size, const char *file)const =0;

};

