#include <QtWidgets>

int main(int argc, char *argv[])
{

    /*
    Here we are creating an instance of the Qwidget object and displaying it.
    A widget which is created without a parent is treated as a window or top-level window.
    */
    /*
    QApplication app(argc, argv);
    QWidget window;
    window.resize(320, 240);
    window.show();
    window.setWindowTitle(
        QApplication::translate("toplevel", "Top-level widget"));
    */



    /*
     * We now add a child widget to the window by passing window as the parent.
    */
    /*
    QPushButton *button = new QPushButton(
        QApplication::translate("childwidget", "Press me"), &window);
    button->move(100, 100);
    button->show();
    */

    /*
    Normally child widgets are arranged inside a window using layout objects rather than by specifying positions and sized explicitly.
    Since we construct the widgets and the layout without parent objects,
    we would expect to see an empty window and two separate windows containing a label and a line edit.
    However, when we tell the layout to manage the label and line edit and set the layout on the window,
    both the widgets and the layout itself are ''reparented'' to become children of the window.
    */
    /*
    QApplication app(argc, argv);
    QWidget window;
    QLabel *label = new QLabel(QApplication::translate("windowlayout", "Name:")); // A label Widget
    QLineEdit *lineEdit = new QLineEdit(); // A line edit widget
    QHBoxLayout *layout = new QHBoxLayout(); // A layout object. Managers such that we do not need to specify things like size or position.

    layout->addWidget(label); // Add widget to the layout.
    layout->addWidget(lineEdit); // Add widget to the layout.
    window.setLayout(layout); // Add layout to the window.
    window.setWindowTitle(
        QApplication::translate("windowlayout", "Window layout"));
    window.show();
    */

    /*
     * Neste layouts.
     * Display a label alongside a line edit at the top of a window, above a table view showing the results of a query.
     */
    QApplication app(argc, argv);
    QWidget window;

    // Three main widgets.
    QLabel *queryLabel = new QLabel(
        QApplication::translate("nestedlayouts", "Query:"));
    QLineEdit *queryEdit = new QLineEdit();
    QTableView *resultView = new QTableView();

    // Add top to query layout.
    QHBoxLayout *queryLayout = new QHBoxLayout();
    queryLayout->addWidget(queryLabel);
    queryLayout->addWidget(queryEdit);

    // Add query layout and table to main layout.
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(queryLayout);
    mainLayout->addWidget(resultView);

    // Add parent layout to window.
    window.setLayout(mainLayout);

    // Set up the model and configure the view...
    QStandardItemModel model;
    model.setHorizontalHeaderLabels({ QApplication::translate("nestedlayouts", "Name"),
                                     QApplication::translate("nestedlayouts", "Office") });

    const QStringList rows[] = {
        QStringList{ QStringLiteral("Verne Nilsen"), QStringLiteral("123") },
        QStringList{ QStringLiteral("Carlos Tang"), QStringLiteral("77") },
        QStringList{ QStringLiteral("Bronwyn Hawcroft"), QStringLiteral("119") },
        QStringList{ QStringLiteral("Alessandro Hanssen"), QStringLiteral("32") },
        QStringList{ QStringLiteral("Andrew John Bakken"), QStringLiteral("54") },
        QStringList{ QStringLiteral("Vanessa Weatherley"), QStringLiteral("85") },
        QStringList{ QStringLiteral("Rebecca Dickens"), QStringLiteral("17") },
        QStringList{ QStringLiteral("David Bradley"), QStringLiteral("42") },
        QStringList{ QStringLiteral("Knut Walters"), QStringLiteral("25") },
        QStringList{ QStringLiteral("Andrea Jones"), QStringLiteral("34") }
    };

    QList<QStandardItem *> items;
    for (const QStringList &row : rows) {
        items.clear();
        for (const QString &text : row)
            items.append(new QStandardItem(text));
        model.appendRow(items);
    }

    resultView->setModel(&model);
    resultView->verticalHeader()->hide();
    resultView->horizontalHeader()->setStretchLastSection(true);
    window.setWindowTitle(
        QApplication::translate("nestedlayouts", "Nested layouts"));
    window.show();


    return app.exec();

}
