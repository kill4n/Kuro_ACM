using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

using System.Net;
using System.Net.Sockets;
using System.Windows.Threading;

namespace noir_WPF
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        byte[] bytes = new byte[1024];
        IPEndPoint ipEnd;
        Socket clientSock = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

        DispatcherTimer dispatcherTimer = new DispatcherTimer();



        public MainWindow()
        {
            InitializeComponent();
            dispatcherTimer.Tick += new EventHandler(dispatcherTimer_Tick);
            dispatcherTimer.Interval = new TimeSpan(0, 0, 0, 0, 500);

        }
        byte[] buff = new byte[1];

        private void dispatcherTimer_Tick(object sender, EventArgs e)
        {
            if (clientSock.Connected)
            {
                if (clientSock.Available > 0)
                {
                    clientSock.Receive(buff);
                    txtData.Text += "" + string.Format("{0:X}\r\n", buff[0]);
                }
            }
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            ipEnd = new IPEndPoint(IPAddress.Parse(txtIP.Text), int.Parse(txtPort.Text));
            clientSock.Connect(ipEnd);
            if (clientSock.Connected)
            {
                this.Title = "Conectado";
                dispatcherTimer.Start();
            }
            else
            {
                this.Title = "Desconectado";
                dispatcherTimer.Stop();
            }
        }
    }
}
