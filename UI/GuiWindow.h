/*!
 * \file GuiWindow.h
 *
 * \brief Gui Window module interface
 *
 * \author      KESKE CEM - EPFL EL BA3
 * \date        02.12.2019
 */

#ifndef GUIWINDOW_H
#define GUIWINDOW_H

#include "ui_form.h"
#include "../RF-UI-Interface/connector.h"
#include "../RF-UI-Interface/ProtocolDefine.h"
#include "gui_logger.h"

#include <memory>

#include <QTimer>
#include <QCloseEvent>
#include <QKeyEvent>


#ifdef SOUND_ON
#include <QMediaPlayer>
#endif



class GuiWindow : public QWidget, public Ui_Form {
    Q_OBJECT
public:
    GuiWindow(std::shared_ptr<Connector> connector);
    void update();

public slots:
    void fill_valve_open_pressed();
    void purge_valve_open_pressed();
    void fill_valve_close_pressed();
    void purge_valve_close_pressed();
    void echo_button_pressed();
    void disconnect_on_pressed();
    void disconnect_off_pressed();
    void arm_pressed();
    void disarm_pressed();
    void open_venting_pressed();
    void close_venting_pressed();
    void start_calibration_pressed();
    void recover_pressed();
    void abort_pressed();
    void manual_mode_pressed();
    void ignition_off_pressed();
    void rssi_request_pressed();
    void reset_button_pressed();
    void refresh_data();
    void xbee_clicked();
    void ignite_clicked();
    void theme_change_clicked();
    void file_transmission_pressed();
    void tvc_boot_pressed();
    void tvc_shutdown_pressed();
    void tvc_abort_pressed();
    void tvc_recover_pressed();
    void lcs_1_checked(bool checked);
    void lcs_2_checked(bool checked);
    void lcs_3_checked(bool checked);
    void lcs_4_checked(bool checked);
    void lcs_launch(bool checked);

private:
    enum Theme {WHITE_ON_BLACK = 0, GREEN_ON_BLACK, BLACK_ON_WHITE, THEME_COUNT};

    void initialize_slots_signals();
    void initialize_style();
    void init_password();
    /**
     * @brief ask_password
     * @return True if the pasworrd was entered correctly.
     */
    bool ask_password();

    void refresh_ack_blinking();
    void refresh_ignition_frame();
    void refresh_telemetry();
    void refresh_gps();
    void refresh_com();
    void refresh_tvc();
    void check_and_show();
    
    void refresh_time();

    void show_ok_X(QLabel*, bool);
    void show_ok(QLabel*);
    void show_dots(QLabel*);
    void show_X(QLabel*);
    void show_on(QLabel*);
    void show_off(QLabel*);
    void show_on_off(QLabel*, bool);

    
    void closeEvent(QCloseEvent * event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void refresh_serial_status();
    void refresh_misses();
    void refresh_ignition_code();
    void refresh_av_state();
    void refresh_payload();
    void refresh_gse();
    void refresh_pp();

    //uint16_t calculate_misses();  can't do it as we don't send the packet number


#ifdef SOUND_ON
    void playSound(const char * url);
    QMediaPlayer* m_player;
#endif

    const char* alarm;
    const char* takeoff;
    const char* hymne;

    Logger logger;

    QTimer * timer_;
    std::shared_ptr<Connector> data_;
    uint64_t tick_counter_;
    uint8_t current_theme_;
    std::string password_;
    bool manual_mode;
    bool ready_ignition_;
    bool xbee_acvite_;
    bool fullscreen_;
    
    //uint64_t missed_count_; can't do it as we don't send the packet number
};

#endif // GUIWINDOW_H
