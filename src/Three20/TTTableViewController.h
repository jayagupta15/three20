#import "Three20/TTModelViewController.h"
#import "Three20/TTTableViewDataSource.h"

@class TTActivityLabel;

@interface TTTableViewController : TTModelViewController {
  UITableView* _tableView;
  TTActivityLabel* _reloadingView;
  id<TTTableViewDataSource> _dataSource;
  id<TTTableViewDataSource> _statusDataSource;
  id<UITableViewDelegate> _tableDelegate;
  UITableViewStyle _tableViewStyle;
  BOOL _variableHeightRows;
}

@property(nonatomic,retain) UITableView* tableView;

/** 
 * The data source used to populate the table view.
 *
 * Setting dataSource has the side effect of also setting model to the value of the
 * dataSource's model property.
 */
@property(nonatomic,retain) id<TTTableViewDataSource> dataSource;

/**
 * The style of the table view.
 */
@property(nonatomic) UITableViewStyle tableViewStyle;

/** 
 * Indicates if the table should support non-fixed row heights.
 */
@property(nonatomic) BOOL variableHeightRows;

/**
 * Initializes and returns a controller having the given style.
 */
- (id)initWithStyle:(UITableViewStyle)style;

/**
 * Creates an delegate for the table view.
 *
 * Subclasses can override this to provide their own table delegate implementation.
 */
- (id<UITableViewDelegate>)createDelegate;

/**
 * Tells the controller that the user selected an object in the table.
 */
- (void)didSelectObject:(id)object atIndexPath:(NSIndexPath*)indexPath;

/**
 * Asks if a URL from that user touched in the table should be opened.
 */
- (BOOL)shouldOpenURL:(NSString*)URL;

/**
 * Tells the controller that the user began dragging the table view.
 */
- (void)didBeginDragging;

/**
 * Tells the controller that the user stopped dragging the table view.
 */
- (void)didEndDragging;

@end
