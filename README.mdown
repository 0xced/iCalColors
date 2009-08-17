## Motivation ##
Because Wil Shipley said ([http://twitter.com/wilshipley/status/3350641174](http://twitter.com/wilshipley/status/3350641174)):
> Know what I'd like? If iCal actually called attention to the current day somehow. Seriously, __light blue__ for current, __light gray__ for sel?

and ([http://twitter.com/wilshipley/status/3351193716](http://twitter.com/wilshipley/status/3351193716)):

> Fun iCal game: Look at your LCD screen from 30° above, and watch the highlights for the "current day" and "selected day" totally disappear.

## Requirements ##
* iCal 3.0.8
* [SIMBL](http://www.culater.net/software/SIMBL/SIMBL.php)

## Installation ##
    xcodebuild install

## Use ##
    defaults write com.apple.iCal TodayColor 00ff00
    defaults write com.apple.iCal SelectedDayColor ffff00
