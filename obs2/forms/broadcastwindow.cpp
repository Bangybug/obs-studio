#include "broadcastwindow.hpp"
#include "broadcastwindow.moc.hpp"

BroadcastWindow::BroadcastWindow(QWidget *parent)
	: QMainWindow(parent),
	ui(new Ui::BroadcastWindow)
{
	setAttribute(Qt::WA_NativeWindow);
	ui->setupUi(this);
}


int BroadcastWindow::getSceneCount()
{
//  main->ui->scenes->count()
	return 0;
}

OBSScene BroadcastWindow::getScene(int index)
{
/*
QListWidgetItem *item = main->ui->scenes->item(i);
OBSScene scene = GetOBSRef<OBSScene>(item);
*/
	return NULL;
}


OBSWeakSource BroadcastWindow::getProgramScene()
{
	return programScene;
}

OBSSource BroadcastWindow::GetCurrentSceneSource()
{
	OBSScene curScene = GetCurrentScene();
	return OBSSource(obs_scene_get_source(curScene));
}

OBSScene BroadcastWindow::GetCurrentScene()
{
	//QListWidgetItem *item = ui->scenes->currentItem();
	//return item ? GetOBSRef<OBSScene>(item) : nullptr;
	return nullptr;
}

int BroadcastWindow::getTransitionCount()
{
	return 0;
}

OBSSource BroadcastWindow::getTransition(int index)
{
//	OBSSource tr = main->ui->transitions->itemData(i).value<OBSSource>();
	return nullptr;
}


OBSSource BroadcastWindow::GetCurrentTransition()
{
//TODO 
	return nullptr;
}



void BroadcastWindow::openSceneCollection(const char* collection)
{
/*
	QList<QAction*> menuActions =
		main->ui->sceneCollectionMenu->actions();
	QString qstrCollection = QT_UTF8(collection);

	for (int i = 0; i < menuActions.count(); i++) {
		QAction *action = menuActions[i];
		QVariant v = action->property("file_name");

		if (v.typeName() != nullptr) {
			if (action->text() == qstrCollection) {
				action->trigger();
				break;
			}
		}
	}
*/
}


void BroadcastWindow::setCurrentProfile(const char* profile)
{
/*
	QList<QAction*> menuActions =
		main->ui->profileMenu->actions();
	QString qstrProfile = QT_UTF8(profile);

	for (int i = 0; i < menuActions.count(); i++) {
		QAction *action = menuActions[i];
		QVariant v = action->property("file_name");

		if (v.typeName() != nullptr) {
			if (action->text() == qstrProfile) {
				action->trigger();
				break;
			}
		}
	}
*/
}


bool BroadcastWindow::isStreamingActive()
{
// return main->outputHandler->StreamingActive();
	return false;
}



bool BroadcastWindow::isRecordingActive()
{
// return main->outputHandler->RecordingActive();
	return false;
}



bool BroadcastWindow::isReplayBufferActive()
{
// return main->outputHandler->ReplayBufferActive();
	return false;
}


void* BroadcastWindow::addToolsMenuAction(const char *name)
{
//	main->ui->menuTools->setEnabled(true);
//	return (void*)main->ui->menuTools->addAction(QT_UTF8(name));
	return nullptr;
}


void BroadcastWindow::addToolsMenuItem(const char *name, obs_frontend_cb callback, void *private_data)
{
/*
main->ui->menuTools->setEnabled(true);

auto func = [private_data, callback] ()
{
callback(private_data);
};

QAction *action = main->ui->menuTools->addAction(QT_UTF8(name));
QObject::connect(action, &QAction::triggered, func);
*/

}


std::unique_ptr<BasicOutputHandler>& BroadcastWindow::getOutputHandler()
{
	return std::unique_ptr<BasicOutputHandler>(nullptr);
}

config_t *BroadcastWindow::getProfileConfig()
{
// return main->basicConfig;
	return nullptr;
}


void BroadcastWindow::SaveProject()
{
}

void BroadcastWindow::SetService(obs_service_t *newService)
{
	if (newService)
		service = newService;
}

obs_service_t *BroadcastWindow::GetService()
{
	if (!service) {
		service = obs_service_create("rtmp_common", NULL, NULL,
			nullptr);
		obs_service_release(service);
	}
	return service;
}

void BroadcastWindow::SaveService()
{
/*
	if (!service)
		return;

	char serviceJsonPath[512];
	int ret = GetProfilePath(serviceJsonPath, sizeof(serviceJsonPath),
		SERVICE_PATH);
	if (ret <= 0)
		return;

	obs_data_t *data = obs_data_create();
	obs_data_t *settings = obs_service_get_settings(service);

	obs_data_set_string(data, "type", obs_service_get_type(service));
	obs_data_set_obj(data, "settings", settings);

	if (!obs_data_save_json_safe(data, serviceJsonPath, "tmp", "bak"))
		blog(LOG_WARNING, "Failed to save service");

	obs_data_release(settings);
	obs_data_release(data);
*/
}


void BroadcastWindow::SetPreviewProgramMode(bool enabled)
{
	// TODO
}


bool BroadcastWindow::isPreviewEnabled()
{
	return previewEnabled;
}

void BroadcastWindow::EnablePreviewDisplay(bool enabled)
{
	previewEnabled = enabled;
	/*
	obs_display_set_enabled(ui->preview->GetDisplay(), enable);
	ui->preview->setVisible(enable);
	ui->previewDisabledLabel->setVisible(!enable);
	*/
}

OBSSource BroadcastWindow::GetProgramSource()
{
	return nullptr;
}

void BroadcastWindow::TransitionToScene(OBSScene scene, bool force = false,
	bool direct = false)
{

}

void BroadcastWindow::TransitionToScene(OBSSource scene, bool force = false,
	bool direct = false, bool quickTransition = false)
{

}


void BroadcastWindow::SetCurrentScene(OBSSource scene, bool force = false,
	bool direct = false)
{

}
