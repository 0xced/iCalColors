//
//  iCalColors.h
//  iCalColors
//
//  Created by Cédric Luthi on 17.08.09.
//  Copyright Cédric Luthi 2009 . All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class CALCanvas, CALCanvasGroup, CALMainCalendarViewController, CALDate;

@interface CALCanvasItem : NSView
{
    long _sn;	// 80 = 0x50
    CALCanvas *_canvas;	// 84 = 0x54
    CALCanvasGroup *_parentGroup;	// 88 = 0x58
    struct _NSSize _size;	// 92 = 0x5c
    struct _NSPoint _position;	// 100 = 0x64
    struct _NSPoint _scale;	// 108 = 0x6c
    float _rotation;	// 116 = 0x74
    struct CGStyle *_shadowStyleRef;	// 120 = 0x78
    struct CGAffineTransform _affineTransform;	// 124 = 0x7c
    struct CGAffineTransform _invertedAffineTransform;	// 148 = 0x94
    struct CGAffineTransform _totalTransform;	// 172 = 0xac
    struct CGAffineTransform _invertedTotalTransform;	// 196 = 0xc4
    BOOL _affineTransformNeedsUpdate;	// 220 = 0xdc
    BOOL _totalTransformNeedsUpdate;	// 221 = 0xdd
    id _delegate;	// 224 = 0xe0
    BOOL _shown;	// 228 = 0xe4
    BOOL _antialiasing;	// 229 = 0xe5
    BOOL _selectable;	// 230 = 0xe6
    NSString *_tagID;	// 232 = 0xe8
    NSMutableDictionary *_userData;	// 236 = 0xec
    NSBezierPath *_bezierPathRepresentation;	// 240 = 0xf0
    NSColor *_strokeColor;	// 244 = 0xf4
    NSColor *_inactiveStrokeColor;	// 248 = 0xf8
    NSColor *_fillColor;	// 252 = 0xfc
    float _lineWidth;	// 256 = 0x100
    BOOL _needsUpdate;	// 260 = 0x104
    NSArray *_firstUpdateRegion;	// 264 = 0x108
    NSCursor *_cursor;	// 268 = 0x10c
    BOOL _shadow;	// 272 = 0x110
    NSString *_shadowStyle;	// 276 = 0x114
    NSMutableSet *_registeredPBoardTypes;	// 280 = 0x118
    BOOL _hasBeenEntered;	// 284 = 0x11c
    BOOL _drawDebugRectangle;	// 285 = 0x11d
    BOOL _grabMouse;	// 286 = 0x11e
    BOOL _grabKeyboard;	// 287 = 0x11f
    BOOL _hasToolTip;	// 288 = 0x120
    int _toolTipTag;	// 292 = 0x124
    NSString *_toolTipString;	// 296 = 0x128
}
@end

@interface CALCanvasGroup : CALCanvasItem
{
    NSMutableArray *_items;	// 300 = 0x12c
    BOOL _clipping;	// 304 = 0x130
    NSColor *_backupColor;	// 308 = 0x134
    BOOL _groupShadows;	// 312 = 0x138
    NSMutableDictionary *_tagsDico;	// 316 = 0x13c
}
@end

@interface CALBackgroundLayerView : CALCanvasGroup
{
    CALMainCalendarViewController *_calendarViewController;	// 320 = 0x140
    CALDate *_selectedTimeRange;	// 324 = 0x144
}
@end

@interface CALBackgroundLayerView (Colors)
+ (void)initialize;	// IMP=0x00019697
- (id)selectedDayColor;	// IMP=0x0004c77d
- (id)todayColor;	// IMP=0x0002cda5
- (id)topOutsideWorkHoursColor;	// IMP=0x0002199c
- (id)bottomOutsideWorkHoursColor;	// IMP=0x000219a6
@end

@interface CALBackgroundLayerView (ColorsHack)
- (id)selectedDayColor;
- (id)todayColor;
@end
