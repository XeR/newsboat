#ifndef NEWSBOAT_LISTWIDGET_H_
#define NEWSBOAT_LISTWIDGET_H_

#include "listmovementcontrol.h"
#include "listwidgetbackend.h"

namespace newsboat {

using OldListWidget = ListMovementControl<ListWidgetBackend>;

} // namespace newsboat

#endif /* NEWSBOAT_LISTWIDGET_H_ */
