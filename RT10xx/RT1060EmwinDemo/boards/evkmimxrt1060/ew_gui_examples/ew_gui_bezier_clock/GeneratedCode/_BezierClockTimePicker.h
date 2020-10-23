/*******************************************************************************
*
* E M B E D D E D   W I Z A R D   P R O J E C T
*
*                                                Copyright (c) TARA Systems GmbH
*                                    written by Paul Banach and Manfred Schweyer
*
********************************************************************************
*
* This software is delivered "as is" and shows the usage of other software 
* components. It is provided as an example software which is intended to be 
* modified and extended according to particular requirements.
* 
* TARA Systems hereby disclaims all warranties and conditions with regard to the
* software, including all implied warranties and conditions of merchantability 
* and non-infringement of any third party IPR or other rights which may result 
* from the use or the inability to use the software.
*
* This file was generated automatically by Embedded Wizard Studio.
*
* Please do not make any modifications of this file! The modifications are lost
* when the file is generated again by Embedded Wizard Studio!
*
* Version  : 9.30
* Date     : 14.02.2020  8:00:50
* Profile  : iMX_RT
* Platform : NXP.iMX_RT.RGB565
*
*******************************************************************************/

#ifndef _BezierClockTimePicker_H
#define _BezierClockTimePicker_H

#ifdef __cplusplus
  extern "C"
  {
#endif

#include "ewrte.h"
#if EW_RTE_VERSION != 0x0009001E
  #error Wrong version of Embedded Wizard Runtime Environment.
#endif

#include "ewgfx.h"
#if EW_GFX_VERSION != 0x0009001E
  #error Wrong version of Embedded Wizard Graphics Engine.
#endif

#include "_CoreSlideTouchHandler.h"
#include "_CoreVerticalList.h"
#include "_TemplatesPickerControl.h"
#include "_ViewsLine.h"
#include "_ViewsText.h"

/* Forward declaration of the class BezierClock::TimePicker */
#ifndef _BezierClockTimePicker_
  EW_DECLARE_CLASS( BezierClockTimePicker )
#define _BezierClockTimePicker_
#endif

/* Forward declaration of the class Core::DialogContext */
#ifndef _CoreDialogContext_
  EW_DECLARE_CLASS( CoreDialogContext )
#define _CoreDialogContext_
#endif

/* Forward declaration of the class Core::Group */
#ifndef _CoreGroup_
  EW_DECLARE_CLASS( CoreGroup )
#define _CoreGroup_
#endif

/* Forward declaration of the class Core::KeyPressHandler */
#ifndef _CoreKeyPressHandler_
  EW_DECLARE_CLASS( CoreKeyPressHandler )
#define _CoreKeyPressHandler_
#endif

/* Forward declaration of the class Core::LayoutContext */
#ifndef _CoreLayoutContext_
  EW_DECLARE_CLASS( CoreLayoutContext )
#define _CoreLayoutContext_
#endif

/* Forward declaration of the class Core::TaskQueue */
#ifndef _CoreTaskQueue_
  EW_DECLARE_CLASS( CoreTaskQueue )
#define _CoreTaskQueue_
#endif

/* Forward declaration of the class Core::View */
#ifndef _CoreView_
  EW_DECLARE_CLASS( CoreView )
#define _CoreView_
#endif

/* Forward declaration of the class Effects::Fader */
#ifndef _EffectsFader_
  EW_DECLARE_CLASS( EffectsFader )
#define _EffectsFader_
#endif

/* Forward declaration of the class Graphics::Canvas */
#ifndef _GraphicsCanvas_
  EW_DECLARE_CLASS( GraphicsCanvas )
#define _GraphicsCanvas_
#endif


/* This is a GUI component. */
EW_DEFINE_FIELDS( BezierClockTimePicker, TemplatesPickerControl )
  EW_PROPERTY( OnChange,        XSlot )
  EW_OBJECT  ( TouchHandlerSecond, CoreSlideTouchHandler )
  EW_OBJECT  ( TouchHandlerMinute, CoreSlideTouchHandler )
  EW_OBJECT  ( TouchHandlerHour, CoreSlideTouchHandler )
  EW_OBJECT  ( ListSecond,      CoreVerticalList )
  EW_OBJECT  ( ListMinute,      CoreVerticalList )
  EW_OBJECT  ( ListHour,        CoreVerticalList )
  EW_OBJECT  ( Separator2,      ViewsText )
  EW_OBJECT  ( Separator1,      ViewsText )
  EW_OBJECT  ( Line1,           ViewsLine )
  EW_OBJECT  ( Line2,           ViewsLine )
  EW_OBJECT  ( Line3,           ViewsLine )
  EW_OBJECT  ( Line4,           ViewsLine )
  EW_OBJECT  ( Line5,           ViewsLine )
  EW_OBJECT  ( Line6,           ViewsLine )
  EW_VARIABLE( ColorSelected,   XColor )
  EW_VARIABLE( ColorUnselected, XColor )
  EW_VARIABLE( ColorLineSliding, XColor )
  EW_VARIABLE( ColorLineNotSliding, XColor )
  EW_VARIABLE( enabled,         XBool )
  EW_VARIABLE( selected,        XBool )
  EW_VARIABLE( sliding,         XBool )
EW_END_OF_FIELDS( BezierClockTimePicker )

/* Virtual Method Table (VMT) for the class : 'BezierClock::TimePicker' */
EW_DEFINE_METHODS( BezierClockTimePicker, TemplatesPickerControl )
  EW_METHOD( initLayoutContext, void )( CoreRectView _this, XRect aBounds, CoreOutline 
    aOutline )
  EW_METHOD( GetRoot,           CoreRoot )( CoreView _this )
  EW_METHOD( Draw,              void )( CoreGroup _this, GraphicsCanvas aCanvas, 
    XRect aClip, XPoint aOffset, XInt32 aOpacity, XBool aBlend )
  EW_METHOD( HandleEvent,       XObject )( CoreView _this, CoreEvent aEvent )
  EW_METHOD( CursorHitTest,     CoreCursorHit )( CoreGroup _this, XRect aArea, XInt32 
    aFinger, XInt32 aStrikeCount, CoreView aDedicatedView, XSet aRetargetReason )
  EW_METHOD( ArrangeView,       XPoint )( CoreRectView _this, XRect aBounds, XEnum 
    aFormation )
  EW_METHOD( MoveView,          void )( CoreRectView _this, XPoint aOffset, XBool 
    aFastMove )
  EW_METHOD( GetExtent,         XRect )( CoreRectView _this )
  EW_METHOD( ChangeViewState,   void )( CoreGroup _this, XSet aSetState, XSet aClearState )
  EW_METHOD( OnSetBounds,       void )( CoreGroup _this, XRect value )
  EW_METHOD( drawContent,       void )( CoreGroup _this, GraphicsCanvas aCanvas, 
    XRect aClip, XPoint aOffset, XInt32 aOpacity, XBool aBlend )
  EW_METHOD( OnSetFocus,        void )( CoreGroup _this, CoreView value )
  EW_METHOD( OnSetBuffered,     void )( CoreGroup _this, XBool value )
  EW_METHOD( OnSetOpacity,      void )( CoreGroup _this, XInt32 value )
  EW_METHOD( IsDialog,          XBool )( CoreGroup _this, XBool aRecursive )
  EW_METHOD( DispatchEvent,     XObject )( CoreGroup _this, CoreEvent aEvent )
  EW_METHOD( BroadcastEvent,    XObject )( CoreGroup _this, CoreEvent aEvent, XSet 
    aFilter )
  EW_METHOD( UpdateLayout,      void )( BezierClockTimePicker _this, XPoint aSize )
  EW_METHOD( UpdateViewState,   void )( BezierClockTimePicker _this, XSet aState )
  EW_METHOD( InvalidateArea,    void )( CoreGroup _this, XRect aArea )
  EW_METHOD( FindSiblingView,   CoreView )( CoreGroup _this, CoreView aView, XSet 
    aFilter )
  EW_METHOD( RestackTop,        void )( CoreGroup _this, CoreView aView )
  EW_METHOD( Remove,            void )( CoreGroup _this, CoreView aView )
  EW_METHOD( Add,               void )( CoreGroup _this, CoreView aView, XInt32 
    aOrder )
EW_END_OF_METHODS( BezierClockTimePicker )

/* The method UpdateLayout() is invoked automatically after the size of the component 
   has been changed. This method can be overridden and filled with logic to perform 
   a sophisticated arrangement calculation for one or more enclosed views. In this 
   case the parameter aSize can be used. It contains the current size of the component. 
   Usually, all enclosed views are arranged automatically accordingly to their @Layout 
   property. UpdateLayout() gives the derived components a chance to extend this 
   automatism by a user defined algorithm. */
void BezierClockTimePicker_UpdateLayout( BezierClockTimePicker _this, XPoint aSize );

/* The method UpdateViewState() is invoked automatically after the state of the 
   component has been changed. This method can be overridden and filled with logic 
   to ensure the visual aspect of the component does reflect its current state. 
   For example, the 'enabled' state of the component can affect its colors (disabled 
   components may appear pale). In this case the logic of the method should modify 
   the respective color properties accordingly to the current 'enabled' state. 
   The current state of the component is passed as a set in the parameter aState. 
   It reflects the very basic component state like its visibility or the ability 
   to react to user inputs. Beside this common state, the method can also involve 
   any other variables used in the component as long as they reflect its current 
   state. For example, the toggle switch component can take in account its toggle 
   state 'on' or 'off' and change accordingly the location of the slider, etc.
   Usually, this method will be invoked automatically by the framework. Optionally 
   you can request its invocation by using the method @InvalidateViewState(). */
void BezierClockTimePicker_UpdateViewState( BezierClockTimePicker _this, XSet aState );

/* This method is called when one of the Slide Touch Handler (TouchHandlerHour, 
   TouchHandlerMinute or TouchHandlerSecond) has finished the slide animation. Thereupon 
   the owner of the time picker is notified, that the time has been changed. */
void BezierClockTimePicker_onEndSlide( BezierClockTimePicker _this, XObject sender );

/* This method is called when one of the Slide Touch Handler (TouchHandlerHour, 
   TouchHandlerMinute or TouchHandlerSecond) has begun the slide animation. */
void BezierClockTimePicker_onStartSlide( BezierClockTimePicker _this, XObject sender );

/* This method is called by 'ListSecond' vertical list every time the list loads 
   or updates an item. */
void BezierClockTimePicker_OnLoadSecondItem( BezierClockTimePicker _this, XObject 
  sender );

/* This method is called by 'ListMinute' vertical list every time the list loads 
   or updates an item. */
void BezierClockTimePicker_OnLoadMinuteItem( BezierClockTimePicker _this, XObject 
  sender );

/* This method is called by 'ListHour' vertical list every time the list loads or 
   updates an item. */
void BezierClockTimePicker_OnLoadHourItem( BezierClockTimePicker _this, XObject 
  sender );

/* 'C' function for method : 'BezierClock::TimePicker.OnGetSecond()' */
XInt32 BezierClockTimePicker_OnGetSecond( BezierClockTimePicker _this );

/* 'C' function for method : 'BezierClock::TimePicker.OnSetSecond()' */
void BezierClockTimePicker_OnSetSecond( BezierClockTimePicker _this, XInt32 value );

/* 'C' function for method : 'BezierClock::TimePicker.OnGetMinute()' */
XInt32 BezierClockTimePicker_OnGetMinute( BezierClockTimePicker _this );

/* 'C' function for method : 'BezierClock::TimePicker.OnSetMinute()' */
void BezierClockTimePicker_OnSetMinute( BezierClockTimePicker _this, XInt32 value );

/* 'C' function for method : 'BezierClock::TimePicker.OnGetHour()' */
XInt32 BezierClockTimePicker_OnGetHour( BezierClockTimePicker _this );

/* 'C' function for method : 'BezierClock::TimePicker.OnSetHour()' */
void BezierClockTimePicker_OnSetHour( BezierClockTimePicker _this, XInt32 value );

/* 'C' function for method : 'BezierClock::TimePicker.onHourUpdate()' */
void BezierClockTimePicker_onHourUpdate( BezierClockTimePicker _this, XObject sender );

/* 'C' function for method : 'BezierClock::TimePicker.onMinuteUpdate()' */
void BezierClockTimePicker_onMinuteUpdate( BezierClockTimePicker _this, XObject 
  sender );

/* 'C' function for method : 'BezierClock::TimePicker.onSecondUpdate()' */
void BezierClockTimePicker_onSecondUpdate( BezierClockTimePicker _this, XObject 
  sender );

#ifdef __cplusplus
  }
#endif

#endif /* _BezierClockTimePicker_H */

/* Embedded Wizard */
