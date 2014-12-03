using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(AzWSASPNETMVC.Startup))]
namespace AzWSASPNETMVC
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
