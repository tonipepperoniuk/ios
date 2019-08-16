//
//  CCMain.h
//  Nextcloud
//
//  Created by Marino Faggiana on 04/09/14.
//  Copyright (c) 2017 Marino Faggiana. All rights reserved.
//
//  Author Marino Faggiana <marino.faggiana@nextcloud.com>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#import <UIKit/UIKit.h>
#import <MobileCoreServices/MobileCoreServices.h>
#import <MediaPlayer/MediaPlayer.h>
#import <AudioToolbox/AudioToolbox.h>
#import <DZNEmptyDataSet/UIScrollView+EmptyDataSet.h>

#import "TWMessageBarManager.h"
#import "AHKActionSheet.h"
#import "BKPasscodeViewController.h"
#import "NSString+TruncateToWidth.h"
#import "CCLogin.h"
#import "CCCellMain.h"
#import "CCCellMainTransfer.h"
#import "CCDetail.h"
#import "CCGraphics.h"
#import "CCSection.h"
#import "CCUtility.h"
#import "CCHud.h"
#import "CCMenuAccount.h"
#import "CCPeekPop.h"
#import <MGSwipeTableCell/MGSwipeTableCell.h>

@class tableMetadata;

@interface CCMain : UIViewController <UITableViewDataSource, UITableViewDelegate, UIActionSheetDelegate, UIGestureRecognizerDelegate, UIViewControllerPreviewingDelegate, BKPasscodeViewControllerDelegate, UISplitViewControllerDelegate, UIPopoverControllerDelegate, UIDocumentMenuDelegate, UIDocumentPickerDelegate, UISearchResultsUpdating, UISearchControllerDelegate, UISearchBarDelegate, UIScrollViewDelegate, DZNEmptyDataSetSource, DZNEmptyDataSetDelegate>

@property (nonatomic, weak) IBOutlet UITableView *tableView;
@property (nonatomic, strong) tableMetadata *metadata;
@property (nonatomic, strong) tableMetadata *metadataForPushDetail;
@property (nonatomic, strong) NSString *serverUrl;
@property (nonatomic, strong) NSString *titleMain;
@property (nonatomic, weak) CCDetail *detailViewController;
@property (nonatomic, strong) UISearchController *searchController;
@property (nonatomic, strong) UIView *reMenuBackgroundView;
@property (nonatomic, strong) UITapGestureRecognizer *singleFingerTap;
@property (nonatomic, strong) NSString *blinkFileNamePath;

@property BOOL isSelectedMode;

- (void)shouldPerformSegue:(tableMetadata *)metadata;
- (void)performSegueDirectoryWithControlPasscode:(BOOL)controlPasscode metadata:(tableMetadata *)metadata blinkFileNamePath:(NSString *)blinkFileNamePath;

- (void)saveToPhotoAlbum:(tableMetadata *)metadata;

- (void)copyFileToPasteboard:(tableMetadata *)metadata;

- (void)closeAllMenu;

- (void)setUINavigationBarDefault;

- (void)readFolder:(NSString *)serverUrl;
- (void)readFileReloadFolder;

- (void)uploadFileAsset:(NSMutableArray *)assets serverUrl:(NSString *)serverUrl useSubFolder:(BOOL)useSubFolder session:(NSString *)session;

- (void)reloadDatasource:(NSString *)serverUrl fileID:(NSString *)fileID action:(NSInteger)action;

- (void)openShareWithMetadata:(tableMetadata *)metadata indexPage:(NSInteger)indexPage;

- (void)clearDateReadDataSource:(NSNotification *)notification;
- (void)cancelSearchBar;

- (void)openAssetsPickerController;
- (void)openImportDocumentPicker;
- (void)createFolder;

@end

