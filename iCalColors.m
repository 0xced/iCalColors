//
//  iCalColors.m
//  iCalColors
//
//  Created by Cédric Luthi on 17.08.09.
//  Copyright Cédric Luthi 2009 . All rights reserved.
//

#import "iCalColors.h"

static NSColor* colorFromString(NSString *colorString, NSColor *defaultColor, CGFloat defaultAlpha)
{
	if ([colorString isKindOfClass:[NSString class]]) {
		long r, g, b, a = defaultAlpha * 255;
		BOOL valid = NO;
		if ([colorString length] >= 6) {
			NSString *red   = [colorString substringWithRange:NSMakeRange(0, 2)];
			NSString *green = [colorString substringWithRange:NSMakeRange(2, 2)];
			NSString *blue  = [colorString substringWithRange:NSMakeRange(4, 2)];
			r = strtol([red UTF8String],   NULL, 16);
			g = strtol([green UTF8String], NULL, 16);
			b = strtol([blue UTF8String],  NULL, 16);
			valid = YES;
		}
		
		if ([colorString length] == 8) {
			NSString *alpha = [colorString substringWithRange:NSMakeRange(6, 2)];
			a = strtol([alpha UTF8String], NULL, 16);
		}
		
		if (valid) {
			return [NSColor colorWithCalibratedRed:r/255. green:g/255. blue:b/255. alpha:a/255.];
		}
	}
	
	return defaultColor;
}



@implementation CALBackgroundLayerView (ColorsHack)

- (id) selectedDayColor
{
	static NSColor* selectedDayColor = nil;
	
	if (!selectedDayColor) {
		NSColor *defaultColor = [NSColor colorWithCalibratedRed:0.568627 green:0.568627 blue:0.568627 alpha:0.12];
		selectedDayColor = colorFromString([[NSUserDefaults standardUserDefaults] objectForKey:@"SelectedDayColor"], defaultColor, 0.12);
		[selectedDayColor retain];
	}
	
	return selectedDayColor;
}

- (id) todayColor
{
	static NSColor* todayColor = nil;
	
	if (!todayColor) {
		NSColor *defaultColor = [NSColor colorWithCalibratedRed:0.223529 green:0.403922 blue:0.72549 alpha:0.12];
		todayColor = colorFromString([[NSUserDefaults standardUserDefaults] objectForKey:@"TodayColor"], defaultColor, 0.12);
		[todayColor retain];
	}
	
	return todayColor;
}

@end



@interface iCalColors :  NSObject {}
@end

@implementation iCalColors

+ (void) initialize
{
	[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(applicationDidFinishLaunching:) name:NSApplicationDidFinishLaunchingNotification object:nil];
}

+ (void) applicationDidFinishLaunching:(NSNotification *)notification
{
	Class CALApplicationController = NSClassFromString(@"CALApplicationController");
	if ([CALApplicationController respondsToSelector:@selector(defaultController)]) {
		id appController = [CALApplicationController performSelector:@selector(defaultController)];
		if ([appController respondsToSelector:@selector(mainController)]) {
			id mainController = [appController performSelector:@selector(mainController)];
			if ([mainController respondsToSelector:@selector(goToCurrentDay:)]) {
				[mainController performSelector:@selector(goToCurrentDay:) withObject:nil];
			}
		}
	}
}

@end
