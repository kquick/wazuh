import yaml
import os
from typing import Optional

from wazuh.core.common import WAZUH_SERVER_YML
from wazuh.core.config.models.server import ServerInternalConfig
from wazuh.core.config.models.central_config import (Config, CommsAPIConfig,
                                                     ManagementAPIConfig, ServerConfig,
                                                     IndexerConfig, EngineConfig)


class CentralizedConfig:
    """Class to manage centralized configuration loading and access.

    Attributes
    ----------
    _config : Optional[Config]
        The loaded configuration object, initialized as None.
    """

    _config: Optional[Config] = None

    @classmethod
    def load(cls):
        """Load the configuration from the YAML file.

        Raises
        ------
        FileNotFoundError
            If the configuration file does not exist.
        """
        if cls._config is None:
            if not os.path.exists(WAZUH_SERVER_YML):
                raise FileNotFoundError(f"Configuration file not found: {WAZUH_SERVER_YML}")
            with open(WAZUH_SERVER_YML, 'r') as file:
                config_data = yaml.safe_load(file)
                cls._config = Config(**config_data)

    @classmethod
    def get_comms_api_config(cls) -> CommsAPIConfig:
        """Retrieve the communications API configuration.

        Returns
        -------
        CommsAPIConfig
            The communications API configuration.

        Loads the configuration if it has not been loaded yet.
        """
        if cls._config is None:
            cls.load()

        return cls._config.communications_api

    @classmethod
    def get_management_api_config(cls) -> ManagementAPIConfig:
        """Retrieve the management API configuration.

        Returns
        -------
        ManagementAPIConfig
            The management API configuration.

        Loads the configuration if it has not been loaded yet.
        """
        if cls._config is None:
            cls.load()

        return cls._config.management_api

    @classmethod
    def get_indexer_config(cls) -> IndexerConfig:
        """Retrieve the indexer configuration.

        Returns
        -------
        IndexerConfig
            The indexer configuration.

        Loads the configuration if it has not been loaded yet.
        """
        if cls._config is None:
            cls.load()

        return cls._config.indexer

    @classmethod
    def get_engine_config(cls) -> EngineConfig:
        """Retrieve the engine configuration.

        Returns
        -------
        EngineConfig
            The engine configuration.

        Loads the configuration if it has not been loaded yet.
        """
        if cls._config is None:
            cls.load()

        return cls._config.engine

    @classmethod
    def get_server_config(cls) -> ServerConfig:
        """Retrieve the server configuration.

        Returns
        -------
        ServerConfig
            The server configuration.

        Loads the configuration if it has not been loaded yet.
        """
        if cls._config is None:
            cls.load()

        return cls._config.server

    @classmethod
    def get_internal_server_config(cls) -> ServerInternalConfig:
        """Retrieve the internal server configuration.

        Returns
        -------
        ServerInternalConfig
            The internal server configuration.

        Loads the configuration if it has not been loaded yet.
        """
        if cls._config is None:
            cls.load()

        return cls._config.server.get_internal_config()
